#include<bits/stdc++.h>
using namespace std;

bool searchIt(int a[], int n, int x){
    int i;
    if(n<=1) return false;
    for(i=0;i<n-1;i++)
        if(a[i]>a[i+1]) break;
    int l=(i+1)%n;
    int h=i;
    while(l!=h){
        if(a[l]+a[h]==x) return true;
        else if(a[l]+a[h]>x){
            h=(n+h-1)%n;
        }
        else {
            l=(l+n+1)%n;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int x;
        cin>>x;
        searchIt(a,n,x)? cout<<"Pair exist" : cout<<"Pair doesn't exist";
        cout<<endl;
    }

return 0;
}
