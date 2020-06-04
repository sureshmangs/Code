Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6




class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
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
        return waterTrap;
    }
};
