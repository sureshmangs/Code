Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.



Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000










class Solution {
public:
    int MAX=100001;

    int find(int x, vector<int> &parent){
        if(parent[x]==-1) return x;
        parent[x]=find(parent[x], parent);
        return parent[x];
    }

    void unionn(int x, int y, vector<int> &parent){
        int xp=find(x, parent);
        int yp=find(y, parent);

        if(xp!=yp)
            parent[yp]=xp;
    }

    int largestComponentSize(vector<int>& A) {
        int n=A.size();
        vector<int> parent(MAX, -1);

        for(int i=0;i<n;i++){
            for(int j=2; j<=sqrt(A[i]);j++){
                if(A[i]%j==0){
                    unionn(A[i], j, parent);
                    unionn(A[i], A[i]/j, parent);
                }
            }
        }

        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            int xp=find(A[i], parent);
            mp[xp+1]++;
        }
        int res=0;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            res=max(res, it->second);
        }
        return res;
    }
};
