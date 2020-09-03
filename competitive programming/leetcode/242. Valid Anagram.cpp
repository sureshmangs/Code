Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?









// Use hash table

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(256, 0);
        int tlen=t.length();
        int slen=s.length();

        if(slen!=tlen) return false;

        for(int i=0;i<tlen;i++)
            freq[t[i]]++;

        for(int i=0;i<slen;i++){
            if(freq[s[i]]<=0) return false;
            freq[s[i]]--;
        }
        return true;
    }
};





// Alter
// Sorting : Sort the two anagrams and check if they are equal or not O(logN)
