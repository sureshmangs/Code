#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int cnt=0;
    bool flag;
    string s;
    while(t--){
        string ch;
        cin>>ch;
        s+=ch;
    }
    int n=s.length();
    for(int i=0;i<n-1;i+=2){
        if(s[i]!=s[i+2]) cnt++;
    }
    cout<<cnt;


return 0;
}
