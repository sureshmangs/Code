#include<bits/stdc++.h>
using namespace std;

void roundToTen(string s){
    int n=s.length();
    bool carry=false;
    if(s[n-1]-'0'<=5) s[n-1]='0';
    else {
        for(int i=n-1;i>=0;i--){
            if(carry){
                int ch=1+s[i]-'0';
                if(ch>9){ ch=0; carry=true; }
                else carry=false;
                s[i]=ch+'0';
                if(carry==false) break;
            }
            else if(s[i]-'0'>5){ carry=true; s[i]='0'; }

        }
    }
    if(carry) cout<<"1"<<s;
    else cout<<s;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin>>ws;  //flush;
    while(t--){

        string s;
        cin>>s;
        roundToTen(s);
    }


return 0;
}
