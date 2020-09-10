#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n=s.length();

    int i=0, maxi=1;

    while(i<n-1){
        int cnt=1;
        while(i<n-1 && s[i]==s[i+1]){
            cnt++;
            i++;
        }

        maxi=max(maxi, cnt);

        i++;
    }

    cout<<maxi;

    return 0;
}
