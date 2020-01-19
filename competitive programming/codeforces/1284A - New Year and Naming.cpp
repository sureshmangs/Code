#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> s;
    vector<string> t;
    for(int i=0;i<n;i++){
        string ch;
        cin>>ch;
        s.push_back(ch);
    }
    for(int i=0;i<m;i++){
        string ch;
        cin>>ch;
        t.push_back(ch);
    }
    int tmp;
    cin>>tmp;
    while(tmp--){
        int year;
        cin>>year;
        --year;
        int a=year%n;
        int b=year%m;
        cout<<s[a]<<t[b]<<endl;
    }


return 0;
}
