Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.


Example 1:

Input: "USA"
Output: True


Example 2:

Input: "FlaG"
Output: False


Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.













class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int sm=0, bg=0;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z') sm++;
            else bg++;
        }
        if(bg==n) return true;
        if(sm==n) return true;
        if((word[0]>='A' && word[0]<='Z') && sm==n-1) return true;
        return false;
    }
};
