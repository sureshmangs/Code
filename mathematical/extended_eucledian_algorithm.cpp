#include<bits/stdc++.h>
using namespace std;

int extendedEuclid(int a, int b, int &x, int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1, y1;
    int gcd=extendedEuclid(b%a, a, x1, y1);
    x=y1-(b/a)*x1;
    y=x1;

    return gcd;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int x, y;
        int gcd=extendedEuclid(a, b, x, y);
        cout<<"ax+by=gcd "<<a<<" "<<x<<" + "<<b<<" "<<y<<" = "<<gcd<<endl;
    }
return 0;
}
