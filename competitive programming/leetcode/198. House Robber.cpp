// Recursive (TLE)

class Solution {
public:

    int robUtil(vector<int> &nums, int i){
        if(i<0)
            return 0;
        return max(nums[i]+robUtil(nums, i-2), robUtil(nums, i-1));
    }

    int rob(vector<int>& nums) {
        return robUtil(nums, nums.size()-1);
    }
};




// Recursive memoized

class Solution {
public:

    int robUtil(vector<int> &nums, int i, vector<int>  &memo){
        if(i<0)
            return 0;
        if(memo[i]>=0) return memo[i];

        return memo[i]=max(nums[i]+robUtil(nums, i-2, memo), robUtil(nums, i-1, memo));
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return robUtil(nums, nums.size()-1, memo);
    }
};




/*
Step 1. Figure out recursive relation.
A robber has 2 options: a) rob current house i; b) don't rob current house.
If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
So it boils down to calculating what is more profitable:

robbery of current house + loot from houses before the previous
loot from the previous house robbery and any loot captured before that
rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )

Step 2. Recursive (top-down)
Converting the recurrent relation from Step 1 shound't be very hard.

Step 3. Recursive + memo (top-down).


//Sourece:   https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
