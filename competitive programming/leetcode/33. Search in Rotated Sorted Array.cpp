Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1








class Solution {
public:

    int pivot(vector<int>&nums){
        int l=0, r=nums.size()-1, mid, n=nums.size();
            while(l<=r){
                mid=l+(r-l)/2;
                int prev=(mid-1+n)%n;
                int next=(mid+1)%n;
                if(nums[mid]<nums[prev] && nums[mid]<nums[next])
                     return mid;
                else if(nums[mid]<nums[r]) r=mid-1;
                else l=mid+1;
            }
            return -1;
    }

    int bSearch(vector<int> &nums, int l, int r, int target){
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<=0) return -1;
       if(n==1){
           if(nums[0]==target) return 0;
           else return -1;
       }

        int piv=pivot(nums);
        int left=bSearch(nums,0, piv-1, target);
        int right=bSearch(nums,piv, n-1, target);
        if(left>=0) return left;
        else if(right>=0) return right;
        else return -1;
    }
};
