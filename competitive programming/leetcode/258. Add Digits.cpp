Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?










class Solution {
public:
    int addDigits(int num) {
           int digitalRoot = 0;
            while (num > 0) {
                digitalRoot += num % 10;
                num = num / 10;

                if (num == 0 && digitalRoot > 9) {
                    num = digitalRoot;
                    digitalRoot = 0;
                }
            }
            return digitalRoot;
    }
};







class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
