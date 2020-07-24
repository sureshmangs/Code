Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?










class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int xor2=0;    // xor of 2 unique numbers
        for(auto &x : nums){
            xor2^=x;
        }
        int setBit=xor2 & (-xor2);    // set bit from rigth to left
        for(auto x: nums){
            if((setBit & x) == 0)
                res[0]^=x;
            else res[1]^=x;
        }
        return res;
    }
};