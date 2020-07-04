Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9








class Solution {
public:
    int first(vector<int> &a, int n, int item){
        int l=0, r=n-1, mid, res=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(a[mid]==item){
                res=mid;    // can be a possible result
                r=mid-1;
            }
            else if(a[mid]<item) l=mid+1;
            else r=mid-1;
        }
        return res;
    }

    int last(vector<int> &a, int n, int item){
        int l=0, r=n-1, mid, res=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(a[mid]==item){
                res=mid;    // can be a possible result
                l=mid+1;
            }
            else if(a[mid]<item) l=mid+1;
            else r=mid-1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& a, int target) {
        vector<int>res;
        int n=a.size();
        int f=first(a, n, target);
        int l=last(a, n, target);
        res.push_back(f);
        res.push_back(l);
        return res;
    }
};
