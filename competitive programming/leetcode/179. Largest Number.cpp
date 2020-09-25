Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.







class Solution {
public:

    static bool comp(int a, int b){
        string as=to_string(a);
        string bs=to_string(b);

        return as+bs > bs+as;

    }

    string largestNumber(vector<int>& nums) {
        string res;

        int cnt=0;

        for(auto x: nums){
            if(x!=0) break;
            cnt++;
        }
        if(cnt==nums.size()) return res+='0';

        sort(nums.begin(), nums.end(), comp);

        for(auto &x: nums)
            res+=to_string(x);

        return res;
    }
};
