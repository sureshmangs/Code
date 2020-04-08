#include<bits/stdc++.h>
using namespace std;

bool isPanLipo(string s){
    bool alp[26]={false};
    int n=s.length(), cnt=0;
    for(int i=0;i<n;i++){
        alp[(s[i]-'a')%26]=true;
    }
    for(int i=0;i<26;i++){
        if(alp[i]) cnt++;
    }
    if(cnt==25) return true;
    else return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t>>ws;
    while(t--){
        string s;
        getline(cin, s);
        if(isPanLipo(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }
return 0;
}
