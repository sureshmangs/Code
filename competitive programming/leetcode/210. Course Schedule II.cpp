There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.















class Solution {
public:

    stack<int> s;

    void dfs(vector<int> adj[],int node, vector<bool> &vis){
        vis[node]=true;
        for(auto x: adj[node]){
            if(!vis[x])
                dfs(adj, x, vis);
        }
        s.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i])
             dfs(adj, i, vis);
        }
        vector<int>res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }

    bool detectCycleUtil(vector<int>adj[], int node, vector<bool> &vis, vector<bool> &rec){
        if(!vis[node]){
            vis[node]=true;
            rec[node]=true;
        }
        for(auto x: adj[node]){
            if(!vis[x] && detectCycleUtil(adj, x, vis, rec)) return true;
            else if(rec[x]==true) return true;
        }
        rec[node]=false;
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]){
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycleUtil(adj, i, vis, rec))  return true;  // cycle exists
            }
        }
        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<int> res;

        if(detectCycle(numCourses, adj)) return res;   // not a DAG

        res=topoSort(numCourses, adj);
        return res;

    }
};
