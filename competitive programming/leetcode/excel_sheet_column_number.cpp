/*
Given a positive integer N, print its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.

Output:
For each testcase, in a new line, print the string corrosponding to the column number.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107

Example:
Input:
1
51
Output:
AY
*/







#include<bits/stdc++.h>
using namespace std;


string convertToTitle(int n) {
        string s;
        while(n>0){
            int ch=n%26;
            if(ch==0){
                s+='Z';
                n=n/26-1;
            }
            else {
                s+=char(ch+'A'-1); // 65 -> A
                n=n/26;
            }

        }
        reverse(s.begin(), s.end());
        return s;
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
        cout<<convertToTitle(n)<<endl;
    }

return 0;
}
