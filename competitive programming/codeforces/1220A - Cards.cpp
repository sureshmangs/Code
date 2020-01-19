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
    int cz=0,cn=0;
    for(int i=0;i<n;i++){
        if(s[i]=='z') cz++;
        else if(s[i]=='n') cn++;
    }
    while(cn--){
        cout<<"1"<<" ";

    }
    while(cz--){
        cout<<"0"<<" ";
    }


return 0;
}
