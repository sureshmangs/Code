#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    bool arr[26];
    memset(arr,false,sizeof(arr));
    int cnt=0;
    int n1=s.length();
    for(int i=0;i<n1;i++){
        int k= int(s[i])- 97;
        arr[k]=true;
    }

    for(int i=0;i<26;i++)
        if(arr[i]==true) cnt++;

    if(cnt%2!=0)
        cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";


return 0;
}
