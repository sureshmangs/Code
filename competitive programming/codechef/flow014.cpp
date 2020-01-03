#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int h;
        float c,t;
        cin>>h>>c>>t;
        bool hh=false, cc=false, tt=false;
        if(h>50) hh=true;
        if(c<0.7) cc=true;
        if(t>5600) tt=true;

        if(hh==true && cc==true && tt==true) cout<<"10"<<endl;
        else if(hh==true && cc==true) cout<<"9"<<endl;
        else if(cc==true && tt==true) cout<<"8"<<endl;
        else if(hh==true && tt==true) cout<<"7"<<endl;
        else if(hh==true || cc==true || tt==true) cout<<"6"<<endl;
        else cout<<"5"<<endl;

    }


return 0;
}
