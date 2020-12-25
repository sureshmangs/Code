/*
We call a positive integer number fair if it is divisible by each of its nonzero digits. For example, 102 is fair (because it is divisible by 1 and 2), but 282 is not, because it isn't divisible by 8. Given a positive integer n. Find the minimum integer x, such that n≤x and x is fair.

Input
The first line contains number of test cases t (1≤t≤103). Each of the next t lines contains an integer n (1≤n≤1018).

Output
For each of t test cases print a single integer — the least fair number, which is not less than n.

Example
inputCopy
4
1
282
1234567890
1000000000000000000
outputCopy
1
288
1234568040
1000000000000000000
Note
Explanations for some test cases:

In the first test case number 1 is fair itself.
In the second test case number 288 is fair (it's divisible by both 2 and 8). None of the numbers from [282,287] is fair, because, for example, none of them is divisible by 8.
*/





#include<bits/stdc++.h>
using namespace std;

bool isFair(long long x){
    long long tmp=x;
    while(x){
        if(x%10!=0 && tmp%(x%10)!=0)return false;
        x/=10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int t;
   cin>>t;
   while(t--){
    long long n;
    cin>>n;

    long long x=n;
    while(1){
        if(isFair(x)) break;
        x++;
    }

    cout<<x<<endl;
   }

    return 0;
}
