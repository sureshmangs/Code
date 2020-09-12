/*
A. Subset Mex
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Given a set of integers (it can contain equal elements).

You have to split it into two subsets A and B (both of them can contain equal elements or be empty). You have to maximize the value of mex(A)+mex(B).

Here mex of a set denotes the smallest non-negative integer that doesn't exist in the set. For example:

mex({1,4,0,2,2,1})=3
mex({3,3,2,1,3,0,0})=4
mex(∅)=0 (mex for empty set)
The set is splitted into two subsets A and B if for any integer number x the number of occurrences of x into this set is equal to the sum of the number of occurrences of x into A and the number of occurrences of x into B.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the size of the set.

The second line of each testcase contains n integers a1,a2,…an (0≤ai≤100) — the numbers in the set.

Output
For each test case, print the maximum value of mex(A)+mex(B).

Example
inputCopy
4
6
0 2 1 5 0 1
3
0 1 2
4
0 2 0 1
6
1 2 3 4 5 6
outputCopy
5
3
4
0
Note
In the first test case, A={0,1,2},B={0,1,5} is a possible choice.

In the second test case, A={0,1,2},B=∅ is a possible choice.

In the third test case, A={0,1,2},B={0} is a possible choice.

In the fourth test case, A={1,3,5},B={2,4,6} is a possible choice.


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

        vector<int> v;
        for(int i=0;i<n;i++){
            int ch;
            cin>>ch;
            v.push_back(ch);
        }

        set<int> a, b;

        for(auto &x: v){
            if(a.find(x)==a.end()){
                a.insert(x);
            } else b.insert(x);
        }


        int i, res=0;
        for(i=0;i<101;i++){
            if(a.find(i)==a.end())
                break;
        }

        res+=i;

        for(i=0;i<101;i++){
            if(b.find(i)==b.end())
                break;
        }

        res+=i;

        cout<<res<<endl;
    }

    return 0;
}
