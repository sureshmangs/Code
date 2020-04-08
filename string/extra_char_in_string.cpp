#include<bits/stdc++.h>
using namespace std;

void extraChar(string s1, string s2){
    int tmp=0;
    int n=s1.length();
    for(int i=0;i<n;i++)
        tmp^=s1[i];
    n=s2.length();
    for(int i=0;i<n;i++)
        tmp^=s2[i];
    cout<<char(tmp)<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin>>ws;  //flush
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        extraChar(s1, s2);
    }


return 0;
}
