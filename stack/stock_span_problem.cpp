#include<bits/stdc++.h>
using namespace std;

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

        stack<pair<int, int> >s;
        vector<int> v;

        for(int i=0;i<n;i++){
            if(s.empty()) v.push_back(-1);
            else if(!s.empty() && s.top().first > a[i]) v.push_back(s.top().second);
            else if(!s.empty() && s.top().first<=a[i]){
                while(!s.empty() && s.top().first<=a[i]){
                    s.pop();
                     if(s.empty()) v.push_back(-1);
                     else if(!s.empty() && s.top().first > a[i]) v.push_back(s.top().second);
                }
            }
            s.push({a[i], i});
        }
        for(int i=0;i<n;i++) cout<<i-v[i]<<" ";
            cout<<endl;
    }



return 0;
}
