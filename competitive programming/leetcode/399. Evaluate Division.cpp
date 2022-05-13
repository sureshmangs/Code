You are given an array of variable pairs equations and an array of real numbers values, 
where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query 
where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not 
result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.











class Solution {
public:
    unordered_map <string, vector <pair<string, double>>> graph;
    unordered_map <string, bool> vis;
    vector <double> calcResult;
    
    bool dfs(string src, string dst, double calculation) {
        vis[src] = true;
        
        if (src == dst) {
            calcResult.push_back(calculation);
            return true;
        }
        
        for (auto v: graph[src]) {
            if (vis[v.first] == false) {
                if (dfs(v.first, dst, calculation * v.second)) return true;
            }
        }
        
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string src = equations[i][0];
            string dst = equations[i][1];
            double value = values[i];
            
            graph[src].push_back({dst, value});
            graph[dst].push_back({src, double(1) / value});
        }
        
        for (int q = 0; q < queries.size(); q++) {
            string src = queries[q][0];
            string dst = queries[q][1];
            
            // clear visited
            for (auto it = vis.begin(); it != vis.end(); it++) {
                it->second = false;
            }
            
            double calculation = 1.0;
            
            // check if src, dst exists in graph
            if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
                calcResult.push_back(-1.0);
            }
            else if (dfs(src, dst, calculation) == false) {
                calcResult.push_back(-1.0);
            }
        }
        
        return calcResult;
    }
};

// TC -> O(q * V)
// SC -> O(V + E)
