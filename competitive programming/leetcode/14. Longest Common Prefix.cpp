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










// word by word matching   O(n2)

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




// character by character by matching O(n2)

class Solution {
public:


    int findMinLen(vector<string> &strs){
        int n=strs.size();
        int minLen=INT_MAX;
        for(int i=0;i<n;i++){
            if(strs[i].length()<minLen) minLen=strs[i].length();
        }
        return minLen;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";

        int minLen=findMinLen(strs);

        string res="";

        for(int i=0;i<minLen;i++){
            char current=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!=current)
                    return res;
            }
            res+=current;
        }

        return res;
    }
};

/*
Suppose you have the input strings as- “geeksforgeeks”, “geeks”, “geek”, “geezer”, “x”

better than word by word
*/






// Sorting O(max* nlogn)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n == 0) return "";

        if(n == 1) return strs[0];

        // Sort the given array (lexiographically ascending order)
        sort(strs.begin(), strs.end());

        // Find the minimum length from first and last string
        int minLen = min(strs[0].length(), strs[n - 1].length());

        // Now the common prefix in first and
        // last string is the longest common prefix
        string first = strs[0], last = strs[n - 1];
        int i = 0;
        while (i < minLen && first[i] == last[i])
            i++;

        return first.substr(0, i);
    }
};




// Other Approaches Divide and Conquer, Binary Search, Trie
