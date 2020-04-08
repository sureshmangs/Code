#include<bits/stdc++.h>
using namespace std;

void missingChars(string s){
    bool alp[26]={false};
    int n=s.length();
    for(int i=0;i<n;i++){
        alp[(s[i]-'a')%26]=true;
    }
    for(int i=0;i<26;i++){
        if(alp[i]==false) cout<<char(i+ 97);
    }
    cout<<endl;

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
        missingChars(s);
    }
return 0;
}
