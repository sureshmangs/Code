Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.












class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0) return "";
        string res=strs[0];
        for(auto str: strs){
            int m=res.length(), n=str.length();
            string tmp="";
            for(int i=0;i< m && i<n; i++){
                if(str[i]==res[i]){
                    tmp+=str[i];  // or tmp+=res[i];
                } else break;
            }
            res=tmp;
        }
        return res;
    }
};
