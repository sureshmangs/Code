Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].









class Solution {
public:
    vector <string> res;
    unordered_map <char, string> mp;
    
    void dfs(int i, string &curr, string &digits) {
        if (i == digits.length()) {
            res.push_back(curr);
            return;
        }
        
        string alpha = mp[digits[i]];
        for (int j = 0; j < alpha.length(); j++) {
            curr += alpha[j];
            dfs(i + 1, curr, digits);
            curr.erase(curr.end() - 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        mp.insert({'2', "abc"});
        mp.insert({'3', "def"});
        mp.insert({'4', "ghi"});
        mp.insert({'5', "jkl"});
        mp.insert({'6', "mno"});
        mp.insert({'7', "pqrs"});
        mp.insert({'8', "tuv"});
        mp.insert({'9', "wxyz"});
        
        
        string curr = "";
        
        if (digits.length() == 0) return res;
        
        dfs(0, curr, digits);
        
        return res;
    }
};


// TC -> O(4 ^ n)
// Consider an example in the worst case where the length is 4 and with string as"9999"
// as 9 is getting mapped to 4 digits ie wxyz, you will have to make 4 * 4 * 4 * 4 permutations 
// which is equivalent to 4 ^ n where n is the length of the string (in this case it is 4). 
// SC -> O(4 ^ n)
