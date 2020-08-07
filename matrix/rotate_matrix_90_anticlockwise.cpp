/*
Given a square matrix mat[][] of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of the square matrix.The second line of each test case contains N x N space separated values of the matrix mat.

Output:
Corresponding to each test case, in a new line, print the rotated array.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 50
1 <= mat[][] <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
5 7 10 9
Output:
3 6 9 2 5 8 1 4 7
7 9 5 10

Explanation:
Testcase 1: Matrix is as below:
1 2 3
4 5 6
7 8 9

Rotating it by 90 degrees in anticlockwise directions will result as below matrix:
3 6 9
2 5 8
1 4 7
*/










#include<bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int> > &matrix){
        int n=matrix.size();
        for(int i=0; i<n/2;i++){
            for(int j=i; j<n-i-1;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[j][n-i-1];  // left bottom goes to left top
                matrix[j][n-i-1]=matrix[n-i-1][n-j-1];  // right bottom goes left bottom
                matrix[n-i-1][n-j-1]=matrix[n-j-1][i];  // right top goes to right bottom
                matrix[n-j-1][i]=tmp;  // left top goes to right top
            }
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > matrix(n, vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ch; cin>>ch;
                matrix[i][j]=ch;
            }
        }

        rotate90(matrix);

        //print
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
        }
               cout<<endl;
    }

return 0;
}
