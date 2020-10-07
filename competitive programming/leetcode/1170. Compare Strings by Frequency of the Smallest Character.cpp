Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.



Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").


Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.











class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;

        vector<int> wordFreq;

        for(auto word: words){
            vector<int> freq(26, 0);
            for(int i=0;i<word.length();i++){
                freq[word[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(freq[i]>0){
                    wordFreq.push_back(freq[i]);
                    break;
                }
            }
        }

        for(auto query: queries){
            vector<int> freq(26, 0);
            for(int i=0;i<query.length();i++){
                freq[query[i]-'a']++;
            }
            int tmp=0, mini=0;
            for(int i=0;i<26;i++){
                if(freq[i]>0){
                   mini=freq[i];
                    break;
                }
            }
            int cnt=0;

            for(int i=0;i<wordFreq.size();i++){
                if(mini<wordFreq[i])
                    cnt++;
            }

            res.push_back(cnt);

        }

        return res;
    }
};
