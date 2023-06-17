Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character











TC -> O(N)
SC -> O(unique characters in string s + t)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> mpST, mpTS;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            if (mpST.find(c1) == mpST.end() && mpTS.find(c2) == mpTS.end()) {
                mpST[c1] = c2;
                mpTS[c2] = c1;
            } else if (mpST[c1] != c2 && mpTS[c2] != c1) return false;
        }
        return true;
    }
};
