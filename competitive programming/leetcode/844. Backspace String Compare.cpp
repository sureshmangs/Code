Given two strings s and t, return true if they are equal when both are typed into 
empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?







// Approach #1: Build String
// TC -> O(M+N), where M,N are the lengths of S and T respectively
// SC ->  O(M + N)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> ss, st;
        
        for (auto &x: s) {
            if (x != '#') ss.push(x);
            else if (!ss.empty()) ss.pop();
        }
        
        for (auto &x: t) {
            if (x != '#') st.push(x);
            else if (!st.empty()) st.pop();
        }
        
        if (ss.size() != st.size()) return false;
        
        while (!ss.empty()) {
            if (ss.top() != st.top()) return false;
            ss.pop();
            st.pop();
        }
        
        return true;
    }
};






// Approach #2: Two Pointer
// Iterate through the string in reverse. 
// If we see a backspace character, the next non-backspace character is skipped. 
// If a character isn't skipped, it is part of the final answer.

// TC -> O(M+N), where M,N are the lengths of S and T respectively
// SC ->  O(1)


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            
            while (j >= 0) {
                if (t[j] == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            
            
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            
            if ((i >= 0) != (j >= 0)) return false;
            
            i--;
            j--;
        }
        
        return true;
    }
};
