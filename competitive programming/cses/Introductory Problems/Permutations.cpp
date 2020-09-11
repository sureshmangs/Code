#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v;

    int curr=n;

    if(curr%2==0){
        while(curr>0){
            v.push_back(curr);
            curr-=2;
        }
        curr=n-1; // for odd
        while(curr>0){
            v.push_back(curr);
            curr-=2;
        }
    } else {
        curr=n-1;  // for even
        while(curr>0){
            v.push_back(curr);
            curr-=2;
        }
        curr=n;
        while(curr>0){
            v.push_back(curr);
            curr-=2;
        }
    }

    bool flag=true;

    for(int i=0;i<n-1;i++){
        if(abs(v[i]-v[i+1])==1){
            flag=false;
            break;
        }
    }

    if(flag){
        for(auto &x: v)
            cout<<x<<" ";
    } else cout<<"NO SOLUTION";

    return 0;
}
