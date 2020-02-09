#include<bits/stdc++.h>
using namespace std;

int pivot(int a[], int n){
    int l=0, h=n-1, mid;
    if(a[l]<=a[h]) return -1;
    while(l<=h){
        mid=l+(h-l)/2;
        if(a[mid]>a[mid+1]) return mid;
        else if(a[mid]<a[mid-1]) return mid-1;
        else {
            if(a[l]<=a[mid]) l=mid+1;
            else h=mid-1;
        }
    }
}

int minSearch(int a[], int n){
    int mini=pivot(a,n);
    mini=(mini+1)%n;
    return a[mini];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<minSearch(a,n)<<endl;
    }



return 0;
}
