#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cf=0,cs=0;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            if(s[i]=='F') cf++;
            else cs++;
        }
    }
    if(cs>cf) cout<<"YES";
    else cout<<"NO";

return 0;
}
