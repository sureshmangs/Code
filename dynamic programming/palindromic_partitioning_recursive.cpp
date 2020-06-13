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

    int partition=INT_MAX;
    for(int k=i;k<j;k++){
        int tmp = 1 + palindromicPartion(s, i, k) + palindromicPartion(s, k+1, j);
        if(tmp<partition) partition=tmp;
    }
    return partition;
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
        cout<<palindromicPartion(s,0,n-1)<<endl;
    }

return 0;
}
