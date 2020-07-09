Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True







int Solution::isPrime(int n) {
    if(n<=1) return 0;
    if(n<=3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(int i=5;i*i<n;i+=6)
        if(n%i==0 || n%(i+2)==0) return 0;
    return 1;
}
