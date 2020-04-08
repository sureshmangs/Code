#include<bits/stdc++.h>
using namespace std;

void decodeCode(string code, string enc){
    char arr[26];
    for(int i=0;i<26;i++){
        arr[(code[i]-'a')%26]=char(i+'a');
    }
    int n=enc.length();
    for(int i=0;i<n;i++){
        cout<<arr[enc[i]-'a'];
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin>>ws;  //flush
    while(t--){
        string code, enc;
        cin>>code>>enc;
        decodeCode(code, enc);

    }


return 0;
}
