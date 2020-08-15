/*
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Example:
Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 3
Output: 7
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
        int n,k;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>k;
        // Implement max heap
        priority_queue<int> maxh;
        for(int i=0;i<n;i++){
            maxh.push(a[i]);
            if(maxh.size()>k) maxh.pop();
        }
        cout<<maxh.top()<<endl;
    }

return 0;
}
