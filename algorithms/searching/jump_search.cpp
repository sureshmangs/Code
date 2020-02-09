#include<bits/stdc++.h>
using namespace std;

int jumpSearch(vector<int> v, int n, int item){
    int m=sqrt(n);
    for(int i=0;i<n;i+=m){
        if(v[i]==item) return i;
        else if(v[i]>item){
            //Linear search
            for(int j=i-m;j<i;j++){
                if(v[j]==item) return j;
            }
            return -1;
        }
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
    int index=jumpSearch(v,n,item);
    if(index>-1) cout<<"Item found at index "<<index;
    else cout<<"Item not found";

return 0;
}
