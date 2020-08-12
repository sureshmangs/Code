Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().



Constraints:

haystack and needle consist only of lowercase English characters.










class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        int found = haystack.find(needle);
        return  found>=0 ? found : -1;
    }
};
