#include<bits/stdc++.h>
using namespace std;

bool pangramCheck(string s, int k){
    int cnt=0;
    bool alp[26]={false};
    int n=s.length();
    for(int i=0;i<n;i++){
           alp[(s[i]-'a')%26]=true;
    }
    for(int i=0;i<26;i++){
            if(alp[i]==true) cnt++;
    }
    if(n<26) return false;
    if(cnt+k >= 26) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int k;
        cin>>k;
        if(pangramCheck(s, k)) cout<<"1\n";
        else cout<<"0\n";
    }



return 0;
}
