/*
Input : x = 2, n = 3
Output : 8

Input : x = 7, n = 2
Output : 49
*/






#include<bits/stdc++.h>
using namespace std;

long long power(int x, int y){
    if(y==0) return 1;
    long long res=1;
    while(y){
        if(y%2!=0) res*=x;
        y/=2;
        x*=x;
    }
    return res;
}

int main(){
    int x, y;
    cin>>x>>y;
    // x^y
    cout<<power(x, y);

    return 0;
}
