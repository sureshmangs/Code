#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin>>ws;
    while(t--){
        string s;
        cin>>s;
        int n=s.length(), cnt=0;
        for(int i=0;i<n-1;){
            if(s[i]!=s[i+1]){
                cnt++;
                i+=2;
            } else i+=1;
        }
        cout<<cnt<<endl;
    }


return 0;
}
