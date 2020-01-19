#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l=0;
    cin>>n;
    for(int i=1;i<n;i++){
        int j=n-i;
        float div=(float)j/i;
        if( (ceil(div)-floor(div)) == 0) l++;
    }
    cout<<l;

return 0;
}
