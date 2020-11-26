Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.



Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045


Constraints:

1 <= n <= 50








class Solution {
public:

    void solve(int n, string &str, int start, string &curr, vector<string> &res){
        if(n==curr.length()){
            res.push_back(curr);
            return;
        }
        if(curr.length()>n) return;

        for(int i=start;i<str.length();i++){
            curr+=str[i];
            solve(n, str, i, curr, res);
            curr.erase(curr.end()-1);
        }
    }

    int countVowelStrings(int n) {
        vector<string> res;
        string curr="";
        string str="aeiou";
        solve(n, str, 0, curr, res);

        return res.size();
    }
};
