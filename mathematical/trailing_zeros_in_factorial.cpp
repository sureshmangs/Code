/*
For an integer n find number of trailing zeroes in n! .

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, it contains an integer 'N'.

Output:
In each seperate line output the answer to the problem.

Constraints:
1 <= T <= 100
1 <= N <= 1000

Example:
Input:
1
9
Output:
1

** For More
*/









#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0, tmp=5;
        while(tmp<=n){
            cnt+=n/tmp;
            tmp*=5;
        }
        cout<<cnt<<endl;
    }

return 0;
}
