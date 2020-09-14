#include<bits/stdc++.h>
using namespace std;

int _gcd(int a, int b){
    if(a==0)
        return b;
    return _gcd(b%a, a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    if(n==1){
        cout<<v[0];
        return 0;
    }

    int lcm=(v[0]*v[1])/_gcd(v[0], v[1]);
    int res=lcm;


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            lcm=(v[i]*v[j])/_gcd(v[i], v[j]);
            res=_gcd(res, lcm);
        }
    }

    cout<<res<<endl;

    return 0;
}

