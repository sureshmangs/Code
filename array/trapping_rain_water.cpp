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






//  TC O(N) SC: O(1)
/*
int trap(vector<int>& height) {
        int trapped=0;
        int n=height.size();
        int l=0, r=n-1;
        int maxLeft=0, maxRight=0;

        while(l<r){
            if(height[l]>height[r]){
                if(height[r]>maxRight) maxRight=height[r];
                else trapped+=maxRight-height[r];
                r--;
            } else {
                if(height[l]>maxLeft) maxLeft=height[l];
                else trapped+=maxLeft-height[l];
                l++;
            }
        }
      return trapped;
     }
*/
