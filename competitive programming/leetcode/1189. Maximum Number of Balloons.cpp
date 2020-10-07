Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.



Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0


Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.








class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.length()==0) return 0;

        unordered_map<char, int> mp;

        for(auto ch: text)
            mp[ch]++;

        string tmp="balloon";
        int n=tmp.length();

        int res=0;

        while(1){
            for(int i=0;i<n;i++){
                if(mp[tmp[i]]>0){
                    mp[tmp[i]]--;
                } else return res;
            }
            res++;
        }
        return res;
    }
};






class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.length()==0) return 0;

        unordered_map<char, int> mp;

        for(auto ch: text)
            mp[ch]++;

        int res=INT_MAX;

        res=min(res,mp['b']);
        res=min(res,mp['a']);
        res=min(res,mp['l']/2);
        res=min(res,mp['o']/2);
        res=min(res,mp['n']);

        return res;
    }
};
