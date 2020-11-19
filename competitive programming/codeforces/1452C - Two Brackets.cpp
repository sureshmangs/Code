/*
You are given a string s, consisting of brackets of two types: '(', ')', '[' and ']'.

A string is called a regular bracket sequence (RBS) if it's of one of the following types:

empty string;
'(' + RBS + ')';
'[' + RBS + ']';
RBS + RBS.
where plus is a concatenation of two strings.

In one move you can choose a non-empty subsequence of the string s (not necessarily consecutive) that is an RBS, remove it from the string and concatenate the remaining parts without changing the order.

What is the maximum number of moves you can perform?

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Each of the next t lines contains a non-empty string, consisting only of characters '(', ')', '[' and ']'. The total length of the strings over all testcases doesn't exceed 2⋅105.

Output
For each testcase print a single integer — the maximum number of moves you can perform on a given string s.

Example
inputCopy
5
()
[]()
([)]
)]([
)[(]
outputCopy
1
2
2
0
1
Note
In the first example you can just erase the whole string.

In the second example you can first erase the brackets on positions 1 and 2: "[]()", then "()" is left. After that you can erase it whole. You could erase the whole string from the beginning but you would get one move instead of two.

In the third example you can first erase the brackets on positions 1 and 3: "([)]". They form an RBS "()". Then "[]" is left, so you can erase it whole.

In the fourth example there is no subsequence that is an RBS, so you can't perform a move at all.

In the fifth example you can erase the brackets on positions 2 and 4: ")[(]" and get ")(" as a result. You can erase nothing from it.
*/











#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        stack<char> s1, s2;

        int res=0;

        for(auto &ch: s){
            if(ch=='(') s1.push('(');
            else if(!s1.empty() && ch==')'){
                res++;
                s1.pop();
            }
        }

        for(auto &ch: s){
            if(ch=='[') s2.push('[');
            else if(!s2.empty() && ch==']'){
                res++;
                s2.pop();
            }
        }
    cout<<res<<"\n";
    }

    return 0;
}


