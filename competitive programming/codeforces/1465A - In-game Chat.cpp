/*
You have been assigned to develop a filter for bad messages in the in-game chat. A message is a string S of length n, consisting of lowercase English letters and characters ')'. The message is bad if the number of characters ')' at the end of the string strictly greater than the number of remaining characters. For example, the string ")bc)))" has three parentheses at the end, three remaining characters, and is not considered bad.

Input
The first line contains the number of test cases t (1≤t≤100). Description of the t test cases follows.

The first line of each test case contains an integer n (1≤n≤100). The second line of each test case contains a string S of length n, consisting of lowercase English letters and characters ')'.

Output
For each of t test cases, print "Yes" if the string is bad. Otherwise, print "No".

You can print each letter in any case (upper or lower).

Example
inputCopy
5
2
))
12
gl))hf))))))
9
gege)))))
14
)aa))b))))))))
1
)
outputCopy
Yes
No
Yes
Yes
Yes

*/




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
        string s;
        cin>>s;

        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') cnt++;
            else break;
        }
        if(cnt>n-cnt) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
