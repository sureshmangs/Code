/*
You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow. Each test case consist of 2 lines. The first line of each test case contains a number denoting the size of the matrix M. Then in the next line are space separated values of the matrix M.

Output:
For each test case output will be the id of the celebrity if present (0 based index). Else -1 will be printed.

User Task:
You will be given a square matrix M[][] where if an element of row i and column j  is set to 1 it means ith person knows jth person. You need to complete the function getId() which finds the id of the celebrity if present else return -1. The function getId() takes two arguments, the square matrix M and its size N.

Note:
M[i][i] will be equal to zero always.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 50
2 <= N <= 501
0 <= M[][] <= 1

Example:
Input :
2
3
0 1 0 0 0 0 0 1 0
2
0 1 1 0
Output :
1
-1

Explanation :
Testcase 1:
For the above test case the matrix will look like
0 1 0
0 0 0
0 1 0
Here,  the celebrity is the person with index 1 ie id 1
Testcase 2:
The matrix will look like
0 1
1 0
Here, there is no such person who is a celebrity (a celebrity should know no one).
*/







#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}



// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    int celeb=0;
    for(int i=1;i<n;i++){
        if(M[celeb][i]==1)
            celeb=i;
    }

    for(int i=0;i<n;i++){
        if(i!=celeb && (M[celeb][i]==1 || M[i][celeb]==0)) return -1;
    }
    return celeb;
}




// Alternative Approach
// Can be solved using the concept of indegree and out degree
//  if a knows b  arrayOfPerson[a]-=1 and arrayOfPerson[b]+=1
// check if some value is equal to n-1 if yes return true else false
