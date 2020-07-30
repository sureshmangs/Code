Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]









// Recursive   (TLE)

class Solution {
public:

    int maxProfitUtil(int i, bool buyOrSell, vector<int>& prices){
        if(i>=prices.size())
            return 0;
        int profit=0;
        if(buyOrSell==false){
            int buy=maxProfitUtil(i+1, true, prices)-prices[i];   // true---> to sell next
            int noBuy=maxProfitUtil(i+1, false, prices);       // false----> to buy next
            profit=max(buy, noBuy);
        } else {
            int sell=maxProfitUtil(i+2, false, prices)+prices[i];   // false--> to buy next    i+2 ---> for cooldown
            int noSell=maxProfitUtil(i+1, true, prices);     // true---->to sell next
            profit=max(sell, noSell);
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        // buyOrSell       false----> buy      true----> sell
        return maxProfitUtil(0, false, prices);    // index, buyOrSell, prices
    }
};







// DP

class Solution {
public:

    unordered_map<string, int> dp;

    int maxProfitUtil(int i, bool buyOrSell, vector<int>& prices){
        if(i>=prices.size())
            return 0;
        string id=to_string(i)+to_string(buyOrSell);
        if(dp.find(id)!=dp.end()) return dp[id];

        int profit=0;
        if(buyOrSell==false){
            int buy=maxProfitUtil(i+1, true, prices)-prices[i];   // true---> to sell next
            int noBuy=maxProfitUtil(i+1, false, prices);       // false----> to buy next
            profit=max(buy, noBuy);
        } else {
            int sell=maxProfitUtil(i+2, false, prices)+prices[i];   // false--> to buy next    i+2 ---> for cooldown
            int noSell=maxProfitUtil(i+1, true, prices);     // true---->to sell next
            profit=max(sell, noSell);
        }
        dp[id]=profit;
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        // buyOrSell       false----> buy      true----> sell
        return maxProfitUtil(0, false, prices);    // index, buyOrSell, prices
    }
};
