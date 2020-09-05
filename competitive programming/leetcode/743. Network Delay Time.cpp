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
typedef pair<int, int> iPair;

class Solution {
public:

    int dijkstras(vector<pair<int, int> > adj[], int N, int K){
        priority_queue<iPair, vector<iPair>, greater<iPair> > q;  // distance, vertex  // min heap
        vector<int> dist(N+1, INF);

        int src=K;
        dist[K]=0;   // starting from here
        q.push({dist[K], src});

        while(!q.empty()){
            int u=q.top().second;
            q.pop();
            for(auto x: adj[u]){
                int v=x.first;
                int w=x.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    q.push({dist[v], v});
                }
            }
        }

        int maxi=dist[1];
        for(int i=1;i<N+1;i++){
            if(dist[i]>maxi) maxi=dist[i];
        }

        return maxi==INF ? -1: maxi;
    }

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int n=times.size();
        vector<pair<int, int> > adj[N+1];  // u: <v, w>  // N+1 as vertex starts from 1
        for(int i=0;i<n;i++)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});

        return dijkstras(adj, N, K);
    }
};
