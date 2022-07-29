There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w),
where u is the source node, v is the target node,
and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal?
If it is impossible, return -1.



Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2


Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
















#define INF INT_MAX
typedef pair <int, int> iPair;
class Solution {
public:
    
    int dijkstras(int src, vector <pair<int, int>> graph[], int n) {
        priority_queue <iPair, vector <iPair>, greater<iPair>> q;
        vector <int> dist(n + 1, INF);
        
        dist[src] = 0;
        q.push({dist[src], src});
        
        
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
     
            for (auto x: graph[u]) {
                int v = x.first;
                int w = x.second;
                
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        int res = INT_MIN;
        for (int i = 1; i <= n; i++) res = max(res, dist[i]);
        
        return res == INT_MAX ? -1: res;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <pair<int, int>> graph[n + 1];
        
        for (auto &time: times) graph[time[0]].push_back({time[1], time[2]});
        
        return dijkstras(k, graph, n);
    }
};

// TC -> O(N+ElogN)
// SC -> O(N+E)
