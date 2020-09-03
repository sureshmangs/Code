Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



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

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.








class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;

        for(auto str: strs){
            string tmp=str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        vector<vector<string> > anagrams;

        for(auto it=mp.begin(); it!=mp.end(); it++)
            anagrams.push_back(it->second);

        return anagrams;
    }
};



// since the string only contains lower-case alphabets
// we can sort them using hash table

class Solution {
public:

    string sortIt(string str){
        vector<int> freq(26, 0);
        int n=str.length();
        for(int i=0;i<n;i++)
            freq[str[i]-'a']++;

        string tmp="";
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                char ch=i+'a';
                tmp.append(freq[i], ch);
            }
        }
        return tmp;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;

        for(auto str: strs){
            string tmp=sortIt(str);
            mp[tmp].push_back(str);
        }

        vector<vector<string> > anagrams;

        for(auto it=mp.begin(); it!=mp.end(); it++)
            anagrams.push_back(it->second);

        return anagrams;
    }
};
