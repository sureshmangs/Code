Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5












class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string tmp;
        ss>>tmp;
        return tmp.length();
    }
};








class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string tmp;
        while(ss>>tmp);
        return tmp.length();
    }
};








class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail=s.length()-1, len=0;
        while(tail>=0 && s[tail]==' ')
            tail--;
        while(tail>=0 && s[tail]!=' '){
            len++;
            tail--;
        }
        return len;
    }
};
