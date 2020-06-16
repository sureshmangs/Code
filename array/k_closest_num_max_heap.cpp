/*
Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3
*/





#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int k, x;
        cin>>k>>x;

        priority_queue<pair<int, int> > maxh;

        for(int i=0;i<n;i++){
            maxh.push({abs(x-arr[i]), arr[i]});
            if(maxh.size()>k) maxh.pop();
        }

        vector<int> res;
        while(!maxh.empty()){
            res.push_back(maxh.top().second);
            maxh.pop();
        }

        sort(res.begin(), res.end());

        for(auto x: res) cout<<x<<" ";
        cout<<endl;
    }

return 0;
}
