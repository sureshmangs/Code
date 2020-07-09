Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d]

If a < c OR a==c AND b < d.










vector<int> Solution::primesum(int n) {
    vector<int> ret;
    vector<bool> seive(n+1, true);
    seive[0]=false;
    seive[1]=false;
    for(int i=2;i*i<=n;i++){
        int tmp=i*2;
        if(seive[i]){
            while(tmp<=n){
                seive[tmp]=false;
                tmp+=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(seive[i] && seive[n-i]){
            ret.push_back(i);
            ret.push_back(n-i);
            break;
        }
    }
    return ret;
}
