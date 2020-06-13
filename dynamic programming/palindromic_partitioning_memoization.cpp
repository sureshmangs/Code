/*
Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1
*/




#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string s, int i, int j){
    if(i==j) return true;
    if(i>j) return true;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int palindromicPartion(string s, int i, int j){
    if(i>=j) return 0;
    if(isPalindrome(s, i, j)) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int partition=INT_MAX;
    int left, right;
    for(int k=i;k<j;k++){
        if(dp[i][k]!=-1) left=dp[i][k];
        else {  left=palindromicPartion(s, i, k);
                dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1) right=dp[k+1][j];
        else {  right=palindromicPartion(s, k+1, j);
                dp[k+1][j]=right;
        }
        int tmp = 1 + left + right;
        if(tmp<partition) partition=tmp;
    }
    return dp[i][j]=partition;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        memset(dp, -1, sizeof(dp));
        cout<<palindromicPartion(s,0,n-1)<<endl;
    }

return 0;
}
