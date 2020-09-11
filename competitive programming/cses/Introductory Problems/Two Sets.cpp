#include<bits/stdc++.h>
using namespace std;

void twoSet(int n){
    long long sum=((long long)n*(n+1))/2;

    if(sum%2!=0){
        cout<<"NO";
        return;
    }

    set<int> s1, s2;
    long long target=sum/2;

    int curr=n;
    long long tSum=0;
    while(curr){
        if(tSum+curr <= target){
            tSum+=curr;
            s1.insert(curr);
        }
        curr--;
    }

    curr=n;
    while(curr){
        if(s1.find(curr)==s1.end())
            s2.insert(curr);

        curr--;
    }

    cout<<"YES\n";
    cout<<s1.size()<<"\n";
    for(auto &x: s1) cout<<x<<" ";
    cout<<"\n";
    cout<<s2.size()<<"\n";
    for(auto &x: s2) cout<<x<<" ";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    twoSet(n);

    return 0;
}
