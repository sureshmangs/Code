Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.













class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        map<char, int> freq;
        for(int i=0;i<n;i++)
            freq[s[i]]++;
        int res=0;
        for(auto it=freq.begin(); it!=freq.end(); it++){
            if(it->second>0){
                if(it->second%2==0){
                    res+=it->second;
                    it->second=0;
                } else {
                    res+=it->second-1;
                    it->second=1;
                }
            }
        }
        for(auto it=freq.begin(); it!=freq.end(); it++){
            if(it->second > 0){
                res+=1;
                break;
            }
        }
        return res;
    }
};
