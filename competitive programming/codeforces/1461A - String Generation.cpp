/*
One fall day Joe got bored because he couldn't find himself something interesting to do. Marty suggested Joe to generate a string of length n to entertain him somehow. It didn't seem particularly difficult, but Joe's generated string had to follow these rules:

the string may only contain characters 'a', 'b', or 'c';
the maximum length of a substring of this string that is a palindrome does not exceed k.

A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end. For example, strings "a", "bc", "abc" are substrings of a string "abc", while strings "ac", "ba", "cba" are not.

A string is a palindrome if it reads the same from the left to the right and from the right to the left. For example, strings "abccba", "abbba", "aba", "abacaba", "a", and "bacab" are palindromes, while strings "abcbba", "abb", and "ab" are not.

Now Joe wants to find any correct string. Help him! It can be proven that the answer always exists under the given constraints.

Input
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤10).

The only line of each test case contains two integers n and k (1≤k≤n≤1000) — the required string length and the maximum length of a palindrome substring, respectively.

Output
For each test case, print any string that satisfies the conditions from the problem statement. If there are multiple correct answers, you can print any one of them. It can be proven that the answer always exists under the given constraints.

Example
inputCopy
2
3 2
4 1
outputCopy
aab
acba
Note
In the first test case of the example, the palindrome substring with the maximum length is "aa". Its length does not exceed 2, so it fits.

In the second test case all palindrome substrings have the length one.

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
         int n, k;
         cin>>n>>k;

         string tmp="abc";
         string res="";
         int start=0;

         for(int i=0;i<n;i++){
            int j=k;
            while(j-- && res.length()<n){
                res+=tmp[start%3];
            }
            start++;
         }

         cout<<res<<endl;
    }

    return 0;
}




