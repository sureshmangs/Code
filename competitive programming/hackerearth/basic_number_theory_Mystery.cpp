Solve the mystery. Using sample input and output, figure out the logic to solve the question.

Input
First number is T, the number of test cases. Next T numbers are integers, N.

Output
Print T lines containing an answer corresponding to the T input numbers.

Constraints
1<=T<=10^4

1<=N<=10^8

SAMPLE INPUT
10
2
6
12
60
5
169
1
8
23
100
SAMPLE OUTPUT
2
4
6
12
2
3
1
4
2
9







#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(i!=n/i) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }

    return 0;
}
