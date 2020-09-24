Given an array nums of integers, return how many of them contain an even number of digits.


Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5








class Solution {
public:

    int getDigits(int n){
        int cnt=0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }

    int findNumbers(vector<int>& nums) {
        int res=0;

        for(auto &num: nums){
            if(getDigits(num)%2==0) res++;
        }
        return res;
    }
};









/*
Only numbers between 10 and 99 or 1000 and 9999 or 100000 have even number of digits.
Taking advantage of nums[i] <= 10^5
Source: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/discuss/461680/C%2B%2B-solution-100-runtime
*/


class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            if(( 10<=n && n<=99) || (1000<=n && n<=9999 ) || ( n==100000 ))
               count++;
        }
        return count;
    }
};
