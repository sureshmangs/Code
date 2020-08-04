Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false


Constraints:

s consists only of printable ASCII characters.













class Solution {
public:

    bool isPalindrome(string s) {
        int n=s.length();
        int i=0, j=n-1;
        while(i<j){
            if(!isalnum(s[i])){ i++; continue; }
            if(!isalnum(s[j])){ j--; continue; }
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
