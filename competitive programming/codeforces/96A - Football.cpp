#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();

    int k=s[0]-'0';
    bool flag=false;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(k==s[i]-'0'){
            cnt++;
            if(cnt==7) { flag=true;  break;  }
        }
        else {
            cnt=1;
            k=s[i]-'0';
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";


return 0;
}
