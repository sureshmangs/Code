Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20







class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int> > res(n, vector<int> (n, 0));

        int r=0, c=0, val=1, m=n;

        while(r<m && c<n){
            for(int i=c;i<n;i++){
                res[r][i]=val++;
            }
            r++;
            for(int i=r;i<m;i++){
                res[i][n-1]=val++;
            }
            n--;
            if(r<m){
                for(int i=n-1;i>=c;i--){
                    res[m-1][i]=val++;
                }
                m--;
            }
            if(c<n){
                for(int i=m-1;i>=r;i--){
                    res[i][c]=val++;
                }
                c++;
            }
        }
        return res;
    }
};
