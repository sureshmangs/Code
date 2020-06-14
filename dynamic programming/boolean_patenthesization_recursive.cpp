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

int booleanParenthesis(string s, int i, int j, bool isTrue){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==true)
             return s[i]=='T';
        else return s[i]=='F';
    }
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
    return ans;
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
        cout<<booleanParenthesis(s, 0, n-1, true)<<endl;
    }

return 0;
}
