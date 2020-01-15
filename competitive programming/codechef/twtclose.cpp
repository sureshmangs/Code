#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    bool arr[n];
    memset(arr,false,sizeof(arr));
    while(k--){
        string s;
        getline(cin,s);
        getline(cin,s);
        int len=s.length();
        if(s[7]=='L')
            cout<<"0"<<endl;
        else{
            int res=0;
            for(int i=6;i<=len;i++){
                int ch=s[i]-'0';
                res=(res*10)+ch;
            }
            if(arr[--res]) {
                arr[--res]=false;
            }
            else {
                arr[--res]=true;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(arr[i]) cnt++;
        cout<<cnt<<endl;
    }

return 0;
}
