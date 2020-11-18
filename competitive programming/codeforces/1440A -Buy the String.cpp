/*
You are given four integers n, c0, c1 and h and a binary string s of length n.

A binary string is a string consisting of characters 0 and 1.

You can change any character of the string s (the string should be still binary after the change). You should pay h coins for each change.

After some changes (possibly zero) you want to buy the string. To buy the string you should buy all its characters. To buy the character 0 you should pay c0 coins, to buy the character 1 you should pay c1 coins.

Find the minimum number of coins needed to buy the string.

Input
The first line contains a single integer t (1≤t≤10) — the number of test cases. Next 2t lines contain descriptions of test cases.

The first line of the description of each test case contains four integers n, c0, c1, h (1≤n,c0,c1,h≤1000).

The second line of the description of each test case contains the binary string s of length n.

Output
For each test case print a single integer — the minimum number of coins needed to buy the string.

Example
inputCopy
6
3 1 1 1
100
5 10 100 1
01010
5 10 1 1
11111
5 1 10 1
11111
12 2 1 10
101110110101
2 100 1 10
00
outputCopy
3
52
5
10
16
22
Note
In the first test case, you can buy all characters and pay 3 coins, because both characters 0 and 1 costs 1 coin.

In the second test case, you can firstly change 2-nd and 4-th symbols of the string from 1 to 0 and pay 2 coins for that.
Your string will be 00000. After that, you can buy the string and pay 5⋅10=50 coins for that. The total number of coins paid will be 2+50=52.
*/






#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, c0, c1, h;
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;

        long long sum=0;

        for(auto &ch: s){
            if(ch=='0') sum+=min(c0, h+c1);
            else sum+=min(c1, h+c0);
        }

        cout<<sum<<endl;
    }


return 0;
}






/* Less Efficient
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, c0, c1, h;
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;

        long long sum=0;

        if(c0==c1){
            sum+=n*c0;
            } else if(c0 > c1){
                if(h<c0){
                    for(int i=0;i<n;i++){
                        if(s[i]=='0'){
                           // s[i]='1';
                            sum+=h;
                        }
                    }
                    sum+=n*c1;
                } else {
                    for(int i=0;i<n;i++){
                        if(s[i]=='0') sum+=c0;
                        else sum+=c1;
                    }
                }
            } else {
                if(h<c1){
                    for(int i=0;i<n;i++){
                        if(s[i]=='1'){
                           // s[i]='0';
                            sum+=h;
                        }
                    }
                    sum+=n*c0;
                } else {
                    for(int i=0;i<n;i++){
                        if(s[i]=='0') sum+=c0;
                        else sum+=c1;
                    }
                }
            }

            long long nc=0;

            for(int i=0;i<n;i++){
                if(s[i]=='0') nc+=c0;
                else nc+=c1;
            }

            sum=min(sum, nc);

            cout<<sum<<endl;
    }


return 0;
}
*/
