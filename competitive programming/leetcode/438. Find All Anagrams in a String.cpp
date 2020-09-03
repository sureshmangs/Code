Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".









/*
Build map from P with frequency of characters, P = 'abc' map = ['a' = 1, 'b' = 1,'c' = 1]
Initially, window Start = 0, window End = 0
Traverse over string S,
if character at windowEnd exists in map decrement that character in map and increment the windowEnd. ( increase the window for valid anagram)
if character does not exist in map, add the character at window start back in map and increment windowStart (reduce the window)
if windowStart and windowEnd are at same index, increment both since size of window is 0.
*/



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen=s.length();
        int plen=p.length();
        vector<int> res;

        vector<int> freq(26, 0);

        for(int i=0;i<plen;i++) freq[p[i]-'a']++;

        int start=0, end=0;  // start and end of the sliding window

        while(end<slen){
            if(freq[s[end]-'a']>0){
                freq[s[end]-'a']--;
                end++; // increment window size

                if(end-start==plen) res.push_back(start);
            }
            // window size of zero
            else if(start==end){
                start++;
                end++;
            }
            // reducing window size
            else if(freq[s[end]-'a']<=0){
                freq[s[start]-'a']++;  // adding deleted elements back
                start++;
            }
        }
        return res;
    }
};
