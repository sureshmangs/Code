/*
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Expected Time Complexity: O(Length(str1) * Length(str2)).
Expected Auxiliary Space: O(Length(str1) * Length(str2)).

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.
*/





#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n, int m){
    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int j=0;j<m+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1])
                 dp[i][j]=1 + dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.length();
        int m=s2.length();
        cout<<n+m-LCS(s1,s2,n,m)<<endl;
    }

return 0;
}





/*
Alternative Approach

int superSeq(string X, string Y, int m, int n)
{
    if (!m) return n;
    if (!n) return m;

    if (X[m - 1] == Y[n - 1])
        return 1 + superSeq(X, Y, m - 1, n - 1);

    return 1 + min(superSeq(X, Y, m - 1, n),
                superSeq(X, Y, m, n - 1));
}
*/
