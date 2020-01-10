#include<bits/stdc++.h>
using namespace std;

int summ(int n){
    return (n*(n+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int d,n;
        cin>>d>>n;
        int res=n;
        while(d--){
            res=summ(res);
        }
        cout<<res<<endl;
    }


return 0;
}
