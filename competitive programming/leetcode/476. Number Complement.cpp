Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.



Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.


Constraints:

The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
num >= 1
You could assume no leading zero bit in the integer’s binary representation.











class Solution {
public:
    int findComplement(int num) {
        int bits = floor(log2(num))+1;
        int tmp = pow(2, bits)-1;
        int res = num^tmp;
        return res;
    }
};




class Solution {
public:
    int findComplement(int num) {
        int bits = floor(log2(num))+1;
        long long tmp = (long long )(1 << bits)-1;       // pow(2, bits) == ( 1 << bits )
        int res = num^tmp;
        return res;
    }
};
