Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.



Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]


Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter






class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;

        vector<int> freq(26, 0);

        string first=A[0];

        for(int i=0;i<first.length();i++)
            freq[first[i]-'a']++;

        for(int i=1;i<A.size();i++){
            vector<int> ftmp(26, 0);
            string tmp=A[i];

            for(int i=0;i<tmp.length();i++)
                ftmp[tmp[i]-'a']++;

            for(int i=0;i<26;i++)
                freq[i]=min(freq[i], ftmp[i]);
        }

        for(int i=0;i<26;i++){
                while(freq[i]>0){
                    res.push_back(string(1, i+'a'));
                    freq[i]--;
                }
            }

            return res;
    }
};
