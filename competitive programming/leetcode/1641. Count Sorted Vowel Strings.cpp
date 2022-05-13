Given an integer n, return the number of strings of length n that consist 
only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, 
s[i] is the same as or comes before s[i+1] in the alphabet.



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







// also finding all the resultant strings
class Solution {
    public:
    void solve(int n, string &str, int start, string &curr, vector<string> &res) {
        if (n == curr.length()) {
            res.push_back(curr);
            return;
        }
        if (curr.length() > n) return;

        for (int i = start; i < str.length(); i++) {
            curr += str[i];
            solve(n, str, i, curr, res);
            curr.erase(curr.end() - 1);
        }
    }

    int countVowelStrings(int n) {
        vector<string> res;
        string curr = "";
        string str = "aeiou";
        solve(n, str, 0, curr, res);

        return res.size();
    }
};












class Solution {
public:
    int res = 0;
    
    void count(int start, int n) {
        if (n == 0) {
            res++;
            return;
        }
        
        for (int i = start; i < 5; i++) {
            count(i, n - 1);
        }
    }
    
    int countVowelStrings(int n) {
        count(0, n);
        return res;
    }
};









/*
a = number of strings that start with a
e = number of strings that start with e
i = number of strings that start with i
o = number of strings that start with o
u = number of strings that start with u
*/

class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int it = 2; it <= n; it++) {
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
            u = u;    // u will always remain one
        }
        return a + e + i + o + u;
    }
};










/*
dp[n][j] means the number of strings constructed by at most j different characters.

If j = 1, use only u
If j = 2, use only o,u
If j = 3, use only i,o,u
If j = 4, use only e,i,o,u
If j = 5, use only a,e,i,o,u

*/



class Solution {
public:
    int countVowelStrings(int n) {
        vector <vector<int>> dp(n + 1, vector <int> (6, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                dp[i][j] = dp[i][j - 1] + (i > 1 ? dp[i - 1][j] : 1);
            }
        }
         return dp[n][5];
    }
};
