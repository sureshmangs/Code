

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        char ch=s[s.length()-1];
        switch(ch){
        case 'o': cout<<"FILIPINO\n"; break;
        case 'u': cout<<"JAPANESE\n"; break;
        case 'a': cout<<"KOREAN\n"; break;}
    }


return 0;
}
