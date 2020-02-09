#include<bits/stdc++.h>
using namespace std;

int searchIt(int a[], int n, int x){
    int l=0, h=n-1, mid;
    while(l<=h){
        mid=l+(h-l)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]<a[h]){
            if(x>a[mid] && x<=a[h]) l=mid+1;
            else h=mid-1;
        }
        else if(a[mid]>a[l]){
            if(x>=a[l] && x<a[mid]) h=mid-1;
            else l=mid+1;
        }
    }
    return -1;
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
        cout<<searchIt(a,n,x)<<endl;
    }

return 0;
}
