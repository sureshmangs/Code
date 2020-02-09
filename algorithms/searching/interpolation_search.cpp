#include<bits/stdc++.h>
using namespace std;

int interpolationSearch(vector<int> v, int n, int item){
    int l=0, h=n-1, pos;
    while(l<=h){
        pos= l+((item-v[l])/(v[h]-v[l])*(h-l));
        if(v[pos]==item) return pos;
        else if(v[pos]>item) h=pos-1;
        else l=pos+1;
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
    int index=interpolationSearch(v,n,item);
    if(index>-1) cout<<"Item found at index "<<index;
    else cout<<"Item not found";

return 0;
}
