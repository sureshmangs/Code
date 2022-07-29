Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, 
be stored in the input character array chars. Note that group lengths that 
are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.










// with extra space

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        
        int cnt = 1;
        
        for (int i = 0; i < n - 1; i++) {
            if (chars[i] == chars[i + 1]) cnt++;
            else if (cnt == 1) s += chars[i];
            else {
                s += chars[i];
                s += to_string(cnt);
                cnt = 1;
            }
        }
        // last character
        if (n - 2 >= 0 && chars[n - 1] == chars[n - 2]) {
            s += chars[n - 1];
            s += to_string(cnt);
        } else s += chars[n - 1];
        
        // modify chars
        int i = 0;
        for (i = 0; i < min(n, (int)s.length()); i++) chars[i] = s[i];
        
        while (i < s.length()) {
            chars.push_back(s[i++]);
        }
            
        return s.length();
    }
};















// without extra space

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cnt = 1, index = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (chars[i] == chars[i + 1]) cnt++;
            else if (cnt == 1) chars[index++] = chars[i];
            else {
                chars[index++] = chars[i];
                for (auto &ch: to_string(cnt)) chars[index++] = ch;
                cnt = 1;
            }
        }
        // last character
        if (n - 2 >= 0 && chars[n - 1] == chars[n - 2]) {
             chars[index++] = chars[n - 1]; 
             for (auto &ch: to_string(cnt)) chars[index++] = ch;
        } else chars[index++] = chars[n - 1];
        
        return index;
    }
};
