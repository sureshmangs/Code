#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n-1];

    for(int i=0;i<n-1;i++) cin>>a[i];

    int res=0;

    for(int i=0;i<n-1;i++)
        res^=a[i];

    for(int i=1;i<=n;i++)
        res^=i;

    cout<<res;


    return 0;
}
