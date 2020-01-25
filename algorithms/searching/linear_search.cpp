#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n, int item){
    for(int i=0;i<n;i++){
        if(a[i]==item) return i;
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
    for(int i=0;i<n;i++) cin>>a[i];
    int item;
    cin>>item;
    int index=linearSearch(a,n,item);
    if(index>=0) cout<<"Found at index "<<index;
    else cout<<"Not found";

return 0;
}
