#include<bits/stdc++.h>
using namespace std;


int gcdd(int a, int b){
    if(a==0) return b;
    return gcdd(b%a, a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<gcdd(a, b)<<endl;
    }
return 0;
}





// TC : O(Log min(a, b))
