/*
Given a number N. The task is to find the nth Catalan number.
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Input:
The first line of input contains a single integer T which denotes the number of test cases. The first line of each test case contains a single integer N.

Output:
For each test case, in a new line print the Catalan number at position N.
Note: Positions start from 0 as shown above.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
3
5
4
10

Output:
42
14
16796
Explanation:
From the given first few Catalan's number we can easily the answer for first two test cases.
*/












#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

int1024_t catalan(int n, int r){
    int1024_t res=1;
    if(r>n-r) r=n-r;
    for(int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
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
        cout<<catalan(2*n,n)/(n+1)<<endl;
    }
return 0;
}
