/*
Chef has an integer N and he wants to generate a matrix M with N rows (numbered 1 through N) and N columns (numbered 1 through N). He thinks that M would be delicious if:

Each element of this matrix is an integer between 1 and N2 inclusive.
All the elements of the matrix are pairwise distinct.
For each square submatrix containing cells in rows r through r+a and in columns c through c+a (inclusive) for some valid integers r, c and a≥0:
Mr,c+Mr+a,c+a is even
Mr,c+a+Mr+a,c is even
Can you help Chef generate a delicious matrix? It can be proved that a solution always exists. If there are multiple solutions, you may find any one.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print N lines describing a delicious matrix M. For each valid i, the i-th of these lines should contain N space-separated integers Mi,1,Mi,2,…,Mi,N.

Constraints
1≤T≤10
1≤N≤103
the sum of N over all test cases does not exceed 103
Subtasks
Subtask #1 (100 points): original constraints

Example Input
1
2
Example Output
1 2
4 3
Explanation
Example case 1: The matrix M has five square submatrices. Four of them ([1], [2], [4], [3]) have a=0, so they obviously satisfy all conditions. The last square submatrix is the whole matrix M, with r=c=a=1, and we can see that M1,1+M2,2=1+3=4 and M1,2+M2,1=2+4=6 are both even.
*/





#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=1;
        int a[n][n];
        if(n%2!=0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    a[i][j]=cnt++;
            }
        } else {
             for(int i=0;i<n;i++){
                if(i%2==0){
                    for(int j=0;j<n;j++)
                        a[i][j]=cnt++;
                } else {
                    for(int j=n-1;j>=0;j--)
                        a[i][j]=cnt++;
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
}
