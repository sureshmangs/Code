#include<bits/stdc++.h>
using namespace std;


int max_sum(int a[],int n)
    {   int sumA=0, r0=0;
        for(int i=0;i<n;i++) sumA+=a[i];
        for(int i=0;i<n;i++) r0+=i*a[i];
        int curRot=r0;
        int maxi=curRot;
        for(int j=1;j<n;j++){
            curRot=curRot+sumA-(n*a[n-j]);
            if(curRot>maxi) maxi=curRot;
        }
        return maxi;
    }
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
        cout<<max_sum(a,n)<<endl;
    }

return 0;
}
