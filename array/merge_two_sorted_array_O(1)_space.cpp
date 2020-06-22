#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        int a1[m], a2[n];
        for(int i=0;i<m;i++) cin>>a1[i];
        for(int i=0;i<n;i++) cin>>a2[i];

        int i=m-1, j=0;
        while(i>=0 && j<n){
            if(a1[i]>a2[j])
                swap(a1[i], a2[j]);
            i--;
            j++;
        }
        sort(a1, a1+m);
        sort(a2, a2+n);

        for(int i=0;i<m;i++) cout<<a1[i]<<" ";
        for(int i=0;i<n;i++) cout<<a2[i]<<" ";
        cout<<endl;
    }



return 0;
}
