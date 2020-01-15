#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int maxi=0, mini=0;
        int n = s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]=='?' || s2[i]=='?') {
                maxi+=1;
            }
            else if(s1[i]!=s2[i]){
                maxi+=1;
                mini+=1;
            }
        }
        cout<<mini<<" "<<maxi<<endl;
    }


return 0;
}
