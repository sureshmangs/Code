The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.








class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        if(n<=1) return v;

        int res=0;
        // xor all the array elements
        for(int i=0;i<n;i++)
            res^=nums[i];
        // xor with all the numbers 1 to n
        for(int i=1;i<=n;i++)
            res^=i;
        // calculate rightmost set bit
        int setBit = res & (-res);
        int x=0, y=0; // missing and duplicate, NOT Respectively

        for(int i=0;i<n;i++){
            if(setBit & nums[i]) x^=nums[i];
            else y^=nums[i];
        }

        for(int i=1;i<=n;i++){
            if(setBit & i) x^=i;
            else y^=i;
        }

        int dup, mis;

        for(int i=0;i<n;i++){
            if(x==nums[i]) { dup=x; mis=y; break; }
            if(y==nums[i]) { dup=y; mis=x; break; }
        }

        v.push_back(dup);
        v.push_back(mis);

        return v;
    }
};
