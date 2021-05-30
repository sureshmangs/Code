Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.

 

Example 1:

Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.
Example 3:

Input: s = "1110"
Output: -1
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.




class Solution {
public:
    
    int helper(string &s, char ch) {
        int cnt = 0;
        
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != ch) cnt++;
        }
        return cnt;
    }
    
    int minSwaps(string s) {
        int n = s.length();
        
        int zero = 0, one = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero++;
            else one++;
        }
        
        if (abs(zero - one) > 1) return -1;
        
        if (zero > one) return helper(s, '0');
        else if (zero < one) return helper(s, '1');
        else return min(helper(s, '0'), helper(s, '1'));
    }
};
