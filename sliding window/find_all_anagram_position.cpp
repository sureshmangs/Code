/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/



class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
       int start = 0, end = 0, match = 0, k = pat.length();
        
       vector <int> res;
	   
	   unordered_map <char, int> m;
	   
	   for (auto &x: pat) m[x]++;
	   
	   while (end < txt.length()) {
	       char right = txt[end];
	       if (m.find(right) != m.end()) {
	           m[right]--;
	           if (m[right] == 0) match++;
	           if (match == m.size()) res.push_back(start);
	       }
	       if (end - start + 1 < k) end++;
	       else if (end - start + 1 == k) {
	           char left = txt[start];
	           if (m.find(left) != m.end()) {
	               if (m[left] == 0) match--;
	               m[left]++;
	           }
	           start++;
	           end++;
	       }
	   }
        
        return res;
    }
};
