Following code tries to figure out if a number is prime ( Wiki )
However, it has a bug in it.
Please correct the bug and then submit the code.




// Return 1 if A is prime, else 0
int Solution::isPrime(int n) {
    if(n<=1) return 0;
    if(n<=3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(int i=5;i*i<n;i+=6){
        if(n%i==0 || n%(i+2)==0) return 0;
    }
    return 1;
}
