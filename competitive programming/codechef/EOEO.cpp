#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long ts, js;
        cin>>ts;
        if(ts%2!=0){
            js=(ts-1)/2;
        } else {
            while(ts%2==0){
                ts/=2;
            }
            js=(ts-1)/2;
        }
        cout<<js<<endl;
    }
return 0;
}
