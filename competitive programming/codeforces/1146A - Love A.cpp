#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    int ca=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a') ca++;
    }
    int other=n-ca;
    if(n==0) cout<<n;
    else if(ca>other) cout<<n;
    else if(ca<=other)
        cout<<ca+ca-1;

return 0;
}
