Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.



Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]


Note:

1 <= N <= 9
0 <= K <= 9










class Solution {
public:

    void dfs(int n, int k, int curr, int i, int prev,vector<int> &res){
        if(i==n-1){
            res.push_back(curr);
            return;
        }
        int next=prev+k;
        if(next<10){
            dfs(n, k, (curr*10)+next, i+1, next, res);
        }
        next=prev-k;
        if(k!=0 && next>=0){
            dfs(n, k, (curr*10)+next, i+1, next, res);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        if(n==1){
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        for(int i=1;i<=9;i++){
            dfs(n, k, i, 0, i, res);  // < n, k, starting digit, size, previous digit, res>
        }
        return res;
    }
};
