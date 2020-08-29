Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?




// O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> lis(n,1);
        for(int i=1;i<n;i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && lis[i] < lis[j]+1)
                    lis[i]=lis[j]+1;
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};



// O(nlogn)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> seq;
        seq.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(seq.back()<nums[i])
                seq.push_back(nums[i]);
            else {
                int index=lower_bound(seq.begin(), seq.end(), nums[i])-seq.begin();
                seq[index]=nums[i];
            }
        }
        return seq.size();
    }
};
