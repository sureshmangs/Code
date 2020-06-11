/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers N and M denoting the length of the strings str1 and str2. Both the strings consist of only small letter alphabets.

The second line of each test case contains the strings str1 and str2.


Output:

Print the total no of insertions and deletions to be done to convert str1 to str2. Output the answer in a new line.


Constraints:

1<= T <=100

1<= N, M <=1000


Example:

Input:

1

4 3

heap pea

Output:

3
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
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        cout<<n+m-2*LCS(s1,s2,n,m)<<endl;
    }

return 0;
}
