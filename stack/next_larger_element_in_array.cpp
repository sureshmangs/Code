/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
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
        long long a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        stack<long long> s;
        vector<long long> v;
        for(int i=n-1;i>=0;i--){

            if(s.empty()==true)
                v.push_back(-1);

            else if(s.empty()==false && s.top()> a[i])
                v.push_back(s.top());

            else if(s.empty()==false && s.top()<=a[i]){
                    while(s.empty()==false && s.top()<=a[i]){
                        s.pop();
                     if(s.empty()==true)
                          v.push_back(-1);
                     else if(s.empty()==false && s.top()> a[i])
                            v.push_back(s.top());
                     }
                    }

            s.push(a[i]);
        }
        for(int i=n-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }



return 0;
}
