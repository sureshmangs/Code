#include<bits/stdc++.h>
using namespace std;

int exponentialSearch(vector<int> v, int n, int item){
    int i=1;
    while(i<n && v[i]<item){
        i*=2;
    }
    int l=i/2, h=i, mid;
    while(l<=h){
        mid=(l+h)/2;
        if(v[mid]==item) return mid;
        else if(v[mid]>item) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ch;
        cin>>ch;
        v.push_back(ch);
    }
    int item;
    cin>>item;
    int index=exponentialSearch(v,n,item);
    if(index>-1) cout<<"Item found at index "<<index;
    else cout<<"Item not found";

return 0;
}
