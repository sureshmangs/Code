/*
Given a boolean expression with following symbols.

Symbols
    'T' ---> true
    'F' ---> false

And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

For Example:
The expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).

Return No_of_ways Mod 1003.

Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is length of string N.  1<=N<=100
Second line is string S (boolean expression).
Output:
No of ways Mod 1003.


Example:
Input:
2
7
T|T&F^T
5
T^F|F

Output:
4
2
*/

#include<bits/stdc++.h>
using namespace std;

int dp[201][201][2];

int booleanParenthesis(string s, int i, int j, bool isTrue){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==true)
             return s[i]=='T';
        else return s[i]=='F';
    }

    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];

    int ans=0, lf, lt, rf, rt;
    for(int k=i+1;k<j;k+=2){
        if(dp[i][k-1][true]!=-1) lt=dp[i][k-1][true];
        else {
            dp[i][k-1][true]=booleanParenthesis(s, i, k-1, true);
            lt=dp[i][k-1][true];
        }
        if(dp[i][k-1][false]!=-1) lf=dp[i][k-1][false];
        else {
            dp[i][k-1][false]=booleanParenthesis(s, i, k-1,false);
            lf=dp[i][k-1][false];
        }
        if(dp[k+1][j][true]!=-1) rt=dp[k+1][j][true];
        else {
            dp[k+1][j][true]=booleanParenthesis(s, k+1, j, true);
            rt=dp[k+1][j][true];
        }
        if(dp[k+1][j][false]!=-1) rf=dp[k+1][j][false];
        else {
            dp[k+1][j][false]=booleanParenthesis(s, k+1, j, false);
            rf=dp[k+1][j][false];
        }

        if(s[k]=='&'){
            if(isTrue==true)
                ans+=lt*rt;
            else ans+=lt*rf + lf*rt + lf*rf;
        } else if(s[k]=='|'){
            if(isTrue==true)
                ans+=lt*rt + lt*rf + lf*rt;
            else ans+=lf*rf;
        } else if(s[k]=='^'){
            if(isTrue==true)
                ans+=lt*rf + lf*rt;
            else ans+=lf*rf + lt*rt;
        }
    }
    return dp[i][j][isTrue]=ans%1003;
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
        string s;
        cin>>s;
        memset(dp, -1, sizeof(dp));
        cout<<booleanParenthesis(s, 0, n-1, true)<<endl;
    }

return 0;
}




/*
Alternative Approach

#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;

int booleanParenthesis(string s, int i, int j, bool isTrue){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==true)
             return s[i]=='T';
        else return s[i]=='F';
    }

    string tmp=to_string(i);
    tmp.push_back(' ');
    tmp.append(to_string(j));
    tmp.push_back(' ');
    tmp.append(to_string(isTrue));

    if(mp.find(tmp)!=mp.end()) return mp[tmp];

    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt=booleanParenthesis(s, i, k-1, true);
        int lf=booleanParenthesis(s, i, k-1, false);
        int rt=booleanParenthesis(s, k+1, j, true);
        int rf=booleanParenthesis(s, k+1, j, false);

        if(s[k]=='&'){
            if(isTrue==true)
                ans+=lt*rt;
            else ans+=lt*rf + lf*rt + lf*rf;
        } else if(s[k]=='|'){
            if(isTrue==true)
                ans+=lt*rt + lt*rf + lf*rt;
            else ans+=lf*rf;
        } else if(s[k]=='^'){
            if(isTrue==true)
                ans+=lt*rf + lf*rt;
            else ans+=lf*rf + lt*rt;
        }
    }
    return mp[tmp]=ans%1003;
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
        string s;
        cin>>s;
        mp.clear();
        cout<<booleanParenthesis(s, 0, n-1, true)<<endl;
    }

return 0;
}
*/
