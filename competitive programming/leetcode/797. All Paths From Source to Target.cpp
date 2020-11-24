Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.












class Solution {
public:

    void dfs(vector<vector<int> > &graph, int src, int dst, vector<int> &curr, vector<vector<int>> &res){
        if(src==dst){
            res.push_back(curr);
            return;
        }
        for(auto x: graph[src]){
            curr.push_back(x);
            dfs(graph, x, dst, curr, res);
            curr.erase(curr.end()-1);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > res;
        vector<int> curr;
        int n=graph.size();
        curr.push_back(0);   // inserting src
        dfs(graph, 0, n-1, curr, res);   // src --> 0    dst --> n-1
        return res;
    }
};





















class Solution {
public:


    void dfs(vector<vector<int> > &graph, int src, int dst, vector<int> &path, vector<vector<int> > &res){

        path.push_back(src);

        if(src==dst){
            res.push_back(path);
            return;
        }

        for(auto &x: graph[src]){
            dfs(graph, x, dst, path, res);
            path.erase(path.end()-1);
        }
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > res;

        int src=0, dst=graph.size()-1;

        vector<int> path;

        dfs(graph, src, dst, path, res);

        return res;
    }
};
