No problem statement.

Find the logic from the given sample input/output.

And answer Q queries.

Constraints :

1 <= Value <= 100000
1<=nunber of query<=10000

SAMPLE INPUT
8
10
30
45
9
69
77
127
150
SAMPLE OUTPUT
8
42
33
4
27
19
1
222










#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    int sum=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            sum+=i;
            if(i!=n/i)
            sum+=n/i;
        }
    }
    sum-=n;
    return sum;
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
