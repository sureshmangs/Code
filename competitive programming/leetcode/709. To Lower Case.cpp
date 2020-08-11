Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.



Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"













class Solution {
public:
    string toLowerCase(string str) {
        int n=str.length();
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z')
                str[i]=str[i]+32;
        }
        return str;
    }
};
