You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

 

Example 1:

Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
Example 2:

Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation: 
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.
 

Constraints:

1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050




class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxi = INT_MIN, res = -1;
        
        vector <int> y(2051, 0);
        
        for (auto &x: logs) {
            for (int i = x[0]; i < x[1]; i++) y[i]++;
        }
        
        for (int i = 1950; i <= 2050; i++) {
            if (maxi < y[i]) {
                maxi = y[i];
                res = i;
            }
        }
        return res;
    }
};
