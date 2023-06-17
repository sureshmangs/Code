Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of 
a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
********************************************************************************










# Approach 1:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        
        for (auto &str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            freq[tmp].push_back(str);
        }

        vector<vector<string>> anagrams;

        for (auto it = freq.begin(); it != freq.end(); it++)
            anagrams.push_back(it->second);

        return anagrams;
    }
};

TC -> O(n), n is the size of strs
SC -> O(n), n is the size of strs
