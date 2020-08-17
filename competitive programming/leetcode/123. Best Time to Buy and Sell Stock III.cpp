
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.










// Dynamic Programming

class Solution {
public:

    int maxPUtil(vector<int> &prices, int i, int buyOrSell, int k, unordered_map<string, int> &dp){
        if(i>=prices.size() || k==0)
            return 0;
        string key=to_string(i)+to_string(buyOrSell)+to_string(k);
        if(dp.find(key)!=dp.end()) return dp[key];
        int res=0;
        if(buyOrSell==0){
            int buy=maxPUtil(prices, i+1, 1, k, dp)-prices[i];
            int noBuy=maxPUtil(prices, i+1, 0, k, dp);
            res+=max(buy, noBuy);
        } else {
            int sell=maxPUtil(prices, i+1, 0, k-1, dp)+prices[i];
            int noSell=maxPUtil(prices, i+1, 1, k, dp);
            res+=max(sell, noSell);
        }
        dp[key]=res;
        return res;
    }

    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> dp;
        return maxPUtil(prices, 0, 0, 2, dp);  // <prices, i, buyOrSell, k, dp>     buy-->0   sell-->1
    }
};













// Recursive (TLE)

class Solution {
public:

    int maxPUtil(vector<int> &prices, int i, int buyOrSell, int k){
        if(i>=prices.size() || k==0)
            return 0;
        int res=0;
        if(buyOrSell==0){
            int buy=maxPUtil(prices, i+1, 1, k)-prices[i];
            int noBuy=maxPUtil(prices, i+1, 0, k);
            res+=max(buy, noBuy);
        } else {
            int sell=maxPUtil(prices, i+1, 0, k-1)+prices[i];
            int noSell=maxPUtil(prices, i+1, 1, k);
            res+=max(sell, noSell);
        }
        return res;
    }

    int maxProfit(vector<int>& prices) {
        return maxPUtil(prices, 0, 0, 2);  // <prices, i, buyOrSell, k>     buy-->0   sell-->1
    }
};
