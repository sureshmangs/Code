Two boys, Venky and Sagar, are at war over a girl, Riu.
Driven by their feelings, they decided to confess to Riu.
Since both of them were equally dumb, Riu decided that she would go out with that boy
 who would successfully find the pattern and thus prove that he is less dumb.

Read input until end of file.

Given : 0<=N<=10^18

SAMPLE INPUT
1
2
3
10
100
SAMPLE OUTPUT
1
2
3
11
121







#include<bits/stdc++.h>
using namespace std;

long long solve(long long n){
    if(n<9) return n;
    return (n%9)+10*solve(n/9);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while(cin>>n){
        long long sum=0;
        cout<<solve(n)<<endl;
    }

    return 0;
}




