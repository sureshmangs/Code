Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.












// Two hashmap

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> all;
        stringstream s(str);
        string tmp;
        while(s>>tmp){
            all.push_back(tmp);
        }

        int plen=pattern.length();
        int alen=all.size();

        if(plen!=alen) return false;

        unordered_map<char, string> mp;
        set<string> unique;

        for(int i=0;i<plen;i++){
            if(mp.find(pattern[i])==mp.end()){
                if(unique.find(all[i])!=unique.end())
                    return false;
                unique.insert(all[i]);
                mp[pattern[i]]=all[i];

            }
            else {
                if(mp[pattern[i]]!=all[i])
                    return false;
            }
        }

        return true;
    }
};








// One map

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> all;
        stringstream s(str);
        string tmp;
        while(s>>tmp){
            all.push_back(tmp);
        }

        int plen=pattern.length();
        int alen=all.size();

        if(plen!=alen) return false;

        unordered_map<string, int> mp;

        for(int i=0;i<plen;i++){
            string ch="#";  // for pattern
            ch+=pattern[i];

            if(mp.find(ch)==mp.end())
                mp[ch]=i;

            if(mp.find(all[i])==mp.end())
                mp[all[i]]=i;

            if(mp[ch]!=mp[all[i]])
                return false;
        }

        return true;
    }
};
