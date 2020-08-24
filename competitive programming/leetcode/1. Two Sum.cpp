Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> v;
        int n=nums.size();
        for(int x=0;x<n;x++){
            if(m.find(target-nums[x])!=m.end()){
                v.push_back(m[target-nums[x]]);
                v.push_back(x);
                return v;
            } else {
                m.insert(make_pair(nums[x], x));
            }
        }
        v.push_back(-1);
        return v;
    }
};













class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_set<int>s;
        vector<int> res;
        int n=v.size();
        int i,j;
        for(i=0;i<n;i++){
            int tmp=target-v[i];
            if(s.find(tmp)!=s.end()){
                for(j=0;j<n && i!=j;j++)
                    if(v[j]==tmp) break;
                res.push_back(j);
                res.push_back(i);
                return res;
            }
            s.insert(v[i]);
        }
       return res;
    }
};




/*
Approach1:
The brute force approach is simple.
Loop through each element xx and find if there is another value that equals to target - xtarget−x.

Approach2:
Sort the array, and use the two pointer technique.
*/
