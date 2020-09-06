Given a string s containing only lower case English letters and the '?' character,
convert all the '?' characters into lower case letters such that the final string does not contain any consecutive repeating characters.
You cannot modify the non '?' characters.

It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

Return the final string after all the conversions (possibly zero) have been made.
If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.



Example 1:

Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
Example 2:

Input: s = "ubv?w"
Output: "ubvaw"
Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
Example 3:

Input: s = "j?qg??b"
Output: "jaqgacb"
Example 4:

Input: s = "??yw?ipkj?"
Output: "acywaipkja"


Constraints:

1 <= s.length <= 100

s contains only lower case English letters and '?'.







class Solution {
public:

    char getValue(int left, int right, string s){
        int n=s.length();
        string value="abc";

        if(left>=0 && right<n){
           for(int i=0;i<3;i++)
               if(value[i]!=s[left] && value[i]!=s[right]) return value[i];
        } else if(left<0){
            for(int i=0;i<3;i++)
               if(value[i]!=s[right]) return value[i];
        } else {
            for(int i=0;i<3;i++)
               if(value[i]!=s[left]) return value[i];
        }

        return 'a'; // ctrl doesnt reach here
    }

    string modifyString(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                    s[i]=getValue(i-1, i+1, s);
            }
        }
        return s;
    }
};
