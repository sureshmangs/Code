#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n, int item){
    int first=0, last=n,mid;

    while(first<=last){
        mid=(first+last)/2;
        if(item==a[mid]) return mid;
        else if(item < a[mid]) last=mid-1;
        else first=mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int item;
    cin>>item;
    int index=binarySearch(a,n,item);
    if(index>=0) cout<<"Found at index "<<index;
    else cout<<"Not found";
return 0;
}
