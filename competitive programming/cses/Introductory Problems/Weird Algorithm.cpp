#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    while(true){
        cout<<n<<" ";
        if(n==1) break;
        if(n%2==0) n/=2;
        else n=3*n+1;
    }

    return 0;
}
