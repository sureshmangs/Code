Given a string word to which you can insert letters "a", "b" or "c" anywhere
and any number of times, return the minimum number of letters that must be
inserted so that word becomes valid.
A string is called valid if it can be formed by concatenating the string "abc" several times.

Example 1:
Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right
next to "a" to obtain the valid string "abc".

Example 2:
Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".

Example 3:
Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed. 

Constraints:
1 <= word.length <= 50
word consists of letters "a", "b" and "c" only.
********************************************************************************









# Approach 1:

class Solution {
public:
    int addMinimum(string word) {
        int res = 0, n = word.size();
        if (word[0] == 'b') res += 1;
        else if (word[0] == 'c') res += 2;
        
        
        for (int i = 0; i < n - 1; i++) {
            if (word[i] == 'a') {
                if (word[i + 1] == 'b') continue;
                else if (word[i + 1] == 'a') res += 2;
                else res += 1;
            } else if (word[i] == 'b') {
                if (word[i + 1] == 'c') continue;
                else if (word[i + 1] == 'a') res += 1;
                else res += 2;
            } else {
                if (word[i + 1] == 'a') continue;
                else if (word[i + 1] == 'b') res += 1;
                else res += 2;
            }
        }
        
        if (word[n - 1] == 'a') res += 2;
        else if (word[n - 1] == 'b') res += 1;

        
        return res;
    }
};

TC -> O(n), n is the length of the word
SC -> (1)
