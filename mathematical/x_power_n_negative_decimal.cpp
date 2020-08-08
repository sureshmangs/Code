/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/







#include<bits/stdc++.h>
using namespace std;

double power(double x, int n) {
    double res=1;
    bool neg=false;
    if(n<0) neg=true;
    n=abs(n);
    while(n){
        if(n%2!=0){
            if(neg) res=res/x;
                else res=res*x;
        }
        x*=x;
        n/=2;
    }
    return res;
}

int main(){
    int x, n;
    cin>>x>>n;
    // x^n
    cout<<double(power(x, n));

    return 0;
}
