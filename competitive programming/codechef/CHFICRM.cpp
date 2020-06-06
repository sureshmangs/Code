#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int five=0, ten=0, fif=0;
        bool flag=true;
        if(a[0]!=5){
            flag=false; n=0;  // to stop the loop
        } else five++;
        for(int i=1;i<n;i++){
            if(a[i]==5) {
                five++;
            } else if(a[i]==10){
                ten++;
                if(five>=1) five--;
                else {
                    flag=false; break;

                }
            } else if(a[i]==15){
                fif++;
                if(ten>=1) ten--;
                    else {
                        if(five>=2) five-=2;
                        else {
                        flag=false; break;
                    }
                }
            }
        }
        if(flag) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }


return 0;
}
