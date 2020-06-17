#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> iPair;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        priority_queue<iPair, vector<iPair>, greater<iPair> > minh;   // min heap
        unordered_map<int, int> mp;  // calculating frequencies
        for(int i=0;i<n;i++) mp[a[i]]++;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            minh.push({it->second, it->first});
            if(minh.size()> k) minh.pop();
        }
        while(!minh.empty()){
            cout<<minh.top().second<<" ";
            minh.pop();
        }
        cout<<endl;
    }
}
