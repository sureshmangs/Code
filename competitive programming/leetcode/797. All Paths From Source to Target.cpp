Given a directed, acyclic graph of N nodes.  
Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  
graph[i] is a list of all nodes j for which the edge (i, j) exists.

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







// We don't need to mark visited as it's a DAG

// TC would be O(n * 2^n) where n = number of nodes.
// Because for each node (n) we are exploring all the possible paths (2^n). 
// And as for each node we have 2 possibilities (either take it or do not take it).
// So, for n nodes total number of paths = 2 * 2 * .. n times = 2^n



// dfs + backtrack
class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int src, int dst, vector <int> &path, vector<vector<int>> &paths) {
        if (src == dst) {
            paths.push_back(path);
            return;
        }
        
        for (auto v: graph[src]) {
                path.push_back(v);
                dfs(graph, v, dst, path, paths);
                
                // backtrack
                path.erase(path.end() - 1);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector <int> path;
        
        path.push_back(0); // adding src = 0 to the path
        
        dfs(graph, 0, graph.size() - 1, path, paths);
        
        return paths;
    }
};




















// dfs + backtrack
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












// bfs
class Solution {
public:
    
    void bfs(vector<vector<int>>& graph, int src, int dst, vector<vector<int>> &paths) {
        queue <vector<int>> q;
        q.push({src});
        
        while (!q.empty()) {
            vector <int> path = q.front();
            q.pop();
            
            int lastVal = path[path.size() - 1];
            
            if (lastVal == dst) {
                paths.push_back(path);
            }
     
            for (auto v: graph[lastVal]) {
                vector <int> tmp = path;
                tmp.push_back(v);
                q.push(tmp);
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        
        bfs(graph, 0, graph.size() - 1, paths);
        
        return paths;
    }
};
