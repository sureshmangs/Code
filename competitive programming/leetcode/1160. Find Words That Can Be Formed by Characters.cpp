You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.



Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation:
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation:
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.








class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>  freq(26, 0);

        int res=0;

        for(auto x: chars) freq[x-'a']++;

        for(auto word: words){
            vector<int> tmp=freq;
            bool flag=true;
            for(auto ch: word){
                if(tmp[ch-'a']<=0){ flag=false; break;}
                tmp[ch-'a']--;
            }
            if(flag) res+=word.length();
        }

        return res;
    }
};
