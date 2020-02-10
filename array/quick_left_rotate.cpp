#include<bits/stdc++.h>
using namespace std;

void quickLeftRotate(int a[], int n, int d){
    d%=n;
    int tmp=n, i=0;
    while(tmp--){
        cout<<a[(i+d)%n]<<" ";
        i++;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, d;
        cin>>n>>d;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        quickLeftRotate(a, n, d);
    }



return 0;
}
