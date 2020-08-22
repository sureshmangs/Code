Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.














class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int min_price=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<min_price) min_price=prices[i];
            else max_profit=max(max_profit, prices[i]-min_price);
        }
        return max_profit;
    }
};




// Recursive implementation
class Solution {
public:
    unordered_map<string, int> dp;
    int maxPro(vector<int> &prices, int i, int buyOrSell, int k){
        if(k==0 || i>=prices.size())
            return 0;
        string key=to_string(i)+to_string(buyOrSell)+to_string(k);
        if(dp.find(key)!=dp.end()) return dp[key];
        int res=0;
        if(buyOrSell==0){
            int buy=maxPro(prices, i+1, 1, k)-prices[i];
            int noBuy=maxPro(prices, i+1, 0, k);
            res=max(buy, noBuy);
        } else {
            int sell=maxPro(prices, i+1, 0, k-1)+prices[i];
            int noSell=maxPro(prices, i+1, 1, k);
            res=max(sell, noSell);
        }
        dp[key]=res;
        return res;
    }

    int maxProfit(vector<int>& prices) {
        return maxPro(prices, 0, 0, 1);  // <prices, start, buyOrSell, number of transactions>    buy--->0   sell--->1
    }
};
