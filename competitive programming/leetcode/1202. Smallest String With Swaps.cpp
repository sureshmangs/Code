You are given a string s, and an array of pairs of indices in the string pairs 
where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.








#define MAX 100000

class Solution {
public:
    vector <int> adj[MAX];
    vector <bool> vis;
    void dfs(int src, vector <char> &characters, vector <int> &indices, string &s) {
        vis[src] = true;
        characters.push_back(s[src]);
        indices.push_back(src);
        
        for (auto &dst: adj[src]) {
            if (!vis[dst]){
                dfs(dst, characters, indices, s);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vis.resize(n, false);
        
        for (auto &pair: pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector <char> characters;
                vector <int> indices;
                
                dfs(i, characters, indices, s);
                
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                for (int index = 0; index < indices.size(); index++) {
                    s[indices[index]] = characters[index];
                }
            }
        }
        return s;
    }
};


// TC: O(VlogV + E)
// SC: O(V + E)
