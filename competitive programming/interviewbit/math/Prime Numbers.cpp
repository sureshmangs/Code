Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.









vector<int> Solution::sieve(int n) {
    vector<int> res;
    vector<bool> prime(n+1, true);
    prime[0]=false;
    prime[1]=false;
    int i=2*2;
    while(i<=n){
        prime[i]=false;   // multiples of 2
         i+=2;
    }
    for(i=3;i*i<n;i+=2){
        int tmp=i*2;
        if(prime[i]){
            while(tmp<=n){
                prime[tmp]=false;
                tmp+=i;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) res.push_back(i);
    }
    return res;
}
