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
        long long a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        stack<long long> s;
        vector<long long> v;
        for(int i=n-1;i>=0;i--){

            if(s.empty()==true)
                v.push_back(-1);

            else if(s.empty()==false && s.top()> a[i])
                v.push_back(s.top());

            else if(s.empty()==false && s.top()<=a[i]){
                    while(s.empty()==false && s.top()<=a[i]){
                        s.pop();
                     if(s.empty()==true)
                          v.push_back(-1);
                     else if(s.empty()==false && s.top()> a[i])
                            v.push_back(s.top());
                     }
                    }

            s.push(a[i]);
        }
        for(int i=n-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }



return 0;
}
