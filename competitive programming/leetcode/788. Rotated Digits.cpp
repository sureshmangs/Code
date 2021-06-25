x is a good number if after rotating each digit individually by 180 degrees, 
we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other (on this case they are rotated in a different direction, in other words 2 or 5 gets mirrored); 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number n, how many numbers x from 1 to n are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Note:

n will be in range [1, 10000].





class Solution {
public:
    
    bool isValid(int n) {
        bool flag = false;
        while (n) {
            int tmp = n % 10;
            if (tmp == 3 || tmp == 4 || tmp == 7) return false;
            if (tmp == 2 || tmp == 5 || tmp == 6 || tmp == 9) flag = true;
            n /= 10;
        }
    
        return flag;
    }
    
    int rotatedDigits(int n) {
        int res = 0;
        
        for (int x = 1; x <= n; x++) {
            if (isValid(x)) res++;
        }
        
        return res;
    }
};
