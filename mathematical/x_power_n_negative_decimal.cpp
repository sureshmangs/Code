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
