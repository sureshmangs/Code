/*
PolandBall is a young, clever Ball. He is interested in prime numbers. He has stated a following hypothesis: "There exists such a positive integer n that for each positive integer m number n·m + 1 is a prime number".

Unfortunately, PolandBall is not experienced yet and doesn't know that his hypothesis is incorrect. Could you prove it wrong? Write a program that finds a counterexample for any n.

Input
The only number in the input is n (1 ≤ n ≤ 1000) — number from the PolandBall's hypothesis.

Output
Output such m that n·m + 1 is not a prime number. Your answer will be considered correct if you output any suitable m such that 1 ≤ m ≤ 103. It is guaranteed the the answer exists.

Examples
inputCopy
3
outputCopy
1
inputCopy
4
outputCopy
2
Note
A prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself.

For the first sample testcase, 3·1 + 1 = 4. We can output 1.

In the second sample testcase, 4·1 + 1 = 5. We cannot output 1 because 5 is prime. However, m = 2 is okay since 4·2 + 1 = 9, which is not a prime number.
*/









#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%(i)==0 || n%(i+1)==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int m;

    for(m=1;m<=100;m++){
        if(!isPrime(n*m+1)){
            break;
        }
    }

    cout<<m;

    return 0;
}
