/*
For a given number N check if it is prime or not. A prime number is a number which is only divisible by 1 and itself.

Input:
First line contains an integer, the number of test cases 'T'. T testcases follow. Each test case should contain a positive integer N.

Output:
For each testcase, in a new line, print "Yes" if it is a prime number else print "No".

Constraints:
1 <= T <= 100
1 <= N <= 109

Example:
Input:
1
5
Output:
Yes

Explanation:
Testcase 1: 5 is the prime number as it is divisible only by 1 and 5.
*/




#include<bits/stdc++.h>
using namespace std;

bool prime(long int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(long int i=5;i<=sqrt(n);i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        prime(n)? cout<<"Yes\n" : cout<<"No\n";
    }

return 0;
}




/*
Prime number is in form of 6p+1, 6p-1
example
6p divisible by 6
6p+1
6p+2 divisible by 2
6p+3 divisible by 3
6p+4 divisible by 4
6p+5 = 6p+6-1 =  6(p+1)-1 = 6X-1
6p+6 divisible by 6
*/
