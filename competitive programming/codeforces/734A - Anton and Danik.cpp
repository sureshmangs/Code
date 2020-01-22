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
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A') cnt++;

    }

    if(cnt > n-cnt) cout<<"Anton";
    else if(cnt < n-cnt) cout<<"Danik";
    else cout<<"Friendship";

return 0;
}
