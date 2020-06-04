#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int maxl[n], maxr[n];
        int maxi;
        // cal maxl
        maxi=a[0]; maxl[0]=a[0];
        for(int i=0;i<n;i++){
            if(a[i]>maxi){ maxi=a[i]; }
            maxl[i]=maxi;
        }

        // cal maxr
        maxi=a[n-1]; maxr[n-1]=a[n-1];
        for(int i=n-1; i>=0; i--){
            if(a[i]>maxi) { maxi=a[i]; }
            maxr[i]=maxi;
        }
        int water[n];
        long long waterTrap=0;
        for(int i=0;i<n;i++){
            water[i]=min(maxl[i], maxr[i])-a[i];
            waterTrap+=water[i];
        }
        cout<<waterTrap<<endl;
    }


return 0;
}
