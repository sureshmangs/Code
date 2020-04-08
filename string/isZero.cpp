
#include<bits/stdc++.h>
using namespace std;

bool isZero(string s){
    if(s[0]-'0'==0) return false;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]-'0'==0) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    cin>>ws; // flush
    while(t--){
        string s;
        cin>>s;
        if(isZero(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }



return 0;
}
