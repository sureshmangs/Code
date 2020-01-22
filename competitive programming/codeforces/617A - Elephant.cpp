#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int cnt=0;
    int i=5;
    while(n){
        int tmp=n/i;
        cnt+=tmp;
        n=n-(tmp*i);
        i--;
    }
    cout<<cnt;

return 0;
}
