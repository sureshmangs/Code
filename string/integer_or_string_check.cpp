#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--){
        string s;
        cin>>s;
        bool isString =false;
        int n=s.length();
        for(int i=0;i<n;i++){
            int ch=s[i]-'0';
            if(!(ch>=0 && ch<=9)) { isString= true; break;}
        }
        if(isString) cout<<"Is a string\n";
            else cout<<"Not a string\n";
    }
return 0;
}
