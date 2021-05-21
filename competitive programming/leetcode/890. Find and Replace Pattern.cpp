Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.







class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> res;
        
        for (auto &word: words) {
            vector <char> m(26, ' ');
            bool flag = true;
            for (int i = 0; i < word.length(); i++) {
                if (m[pattern[i] - 'a'] == ' ') {
                    int cnt = 0;
                    for (auto &ch: m) {
                        if (ch == word[i]) cnt++;
                    }
                    if (cnt != 0) {
                        flag = false; break;
                    }
                    m[pattern[i] - 'a'] = word[i];
                }
                else if (word[i] != m[pattern[i] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        return res;
    }
};

