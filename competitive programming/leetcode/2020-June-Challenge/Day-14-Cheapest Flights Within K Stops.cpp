There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.


Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.







class Solution {
public:

   void dfs(vector<pair<int, int> > adj[], int src, int dst, int k, int &fare, int totCost, bool vis[]){
        if(k<-1) return;
        if(src==dst){
            fare=min(fare, totCost);
            return;
        }

        vis[src]=true;
        for(auto it=adj[src].begin(); it!=adj[src].end();it++){
            int d=it->first;
            int w=it->second;
            if(!vis[d] && totCost+w<=fare)
                dfs(adj, d, dst, k-1, fare, totCost+w, vis);
        }
       vis[src]=false;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int> > adj[n];
        int fSize=flights.size();
        for(int i=0;i<fSize;i++){
            int s=flights[i][0];
            int d=flights[i][1];
            int w=flights[i][2];
            adj[s].push_back({d, w});
        }

        bool vis[n];
        memset(vis, false, sizeof(vis));

        int fare=INT_MAX;

        dfs(adj, src, dst, k, fare, 0, vis);

        if(fare==INT_MAX) return -1;
        else return fare;
    }
};
