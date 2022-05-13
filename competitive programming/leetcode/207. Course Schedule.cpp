There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 
you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
is it possible for you to finish all courses?



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.


Constraints:

The input prerequisites is a graph represented by a list of edges, 
not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5





class Solution {
    public:
    vector <bool> vis, dfsVis;
    
    bool dfs(int src, vector<int> adj[]) {
        vis[src] = true;
        dfsVis[src] = true;

        for (auto &v : adj[src]) {
            if (!vis[v]) {
                if (dfs(v, adj)) return true;  // has cycle
            } else if (dfsVis[v])
                return true;  // has cycle
        }
        dfsVis[src] = false;
        return false;  // no cycle
    }

    bool canFinish(int numCourses, vector<vector<int>> &preReq) {
        vector<int> adj[numCourses];
        
        for (int i = 0; i < preReq.size(); i++) {
            adj[preReq[i][0]].push_back(preReq[i][1]);
        }
        
        vis.resize(numCourses, false);
        dfsVis.resize(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i])
                if (dfs(i, adj)) {
                    // cycle exists, coureses cannot be taken
                    return false;
                }
        }
        // cycle doesn't exist, courses can be taken
        return true;
    }
};
