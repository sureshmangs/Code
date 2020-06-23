Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]








class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int> > res;
        if(n==0) return res;
        int tmp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j || j==0)
                    tmp[i][j]=1;
                else tmp[i][j]=tmp[i-1][j-1]+tmp[i-1][j];
            }
        }

        for(int i=0;i<n;i++){
            vector<int> res1;
            for(int j=0;j<=i;j++){
                res1.push_back(tmp[i][j]);
            }
            res.push_back(res1);
        }
        return res;
    }
};
