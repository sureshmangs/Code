Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.








class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string res, tmp;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                res+=tmp+ ' ';
                tmp="";
                continue;
            }
            tmp=s[i]+tmp;
        }
        res+=tmp;  // adding tmp again as we don't have space in the end
        return res;
    }
};




// Alter
// We can also use stack
