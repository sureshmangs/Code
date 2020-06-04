#include<bits/stdc++.h>
using namespace std;

vector<int> nsl(long long a[], int n){
    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()) v.push_back(-1);
        else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
        else if(!s.empty() && a[s.top()]>=a[i]){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
                 if(s.empty()) v.push_back(-1);
                 else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
            }
        }
        s.push(i);
    }
    return v;
}

vector<int> nsr(long long a[], int n){
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()) v.push_back(n);
        else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
        else if(!s.empty() && a[s.top()]>=a[i]){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
                 if(s.empty()) v.push_back(n);
                 else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>left=nsl(a,n);
        vector<int>right=nsr(a,n);
        vector<int> width;
        for(int i=0;i<n;i++){
            width.push_back(right[i]-left[i]-1);
        }
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(width[i]*a[i] > maxi) maxi=width[i]*a[i];
        }
        cout<<maxi<<endl;
    }


return 0;
}
