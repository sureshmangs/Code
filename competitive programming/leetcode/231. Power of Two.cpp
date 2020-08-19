Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false





class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(abs(floor(log2(n))-ceil(log2(n)))==0) return true;
         else return false;
    }
};





class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        return n && !(n & (n-1));
    }
};


/*
Properties for numbers which are powers of 2, is that they have one and only one bit set in their binary representation.

If the number is neither zero nor a power of two, it will have 1 in more than one place.

So if x is a power of 2 then x & (x-1) will be 0.


x = 4 = (100)2
x - 1 = 3 = (011)2
x & (x-1) = 4 & 3 = (100)2 & (011)2 = (000)2

x = 6 = (110)2
x - 1 = 5 = (101)2
x & (x-1) = 6 & 5 = (110)2 & (101)2 = (100)2

For a x, the binary representation of (x-1) can be obtained by simply flipping all the bits to the right of rightmost 1 in x and also including the rightmost 1.
*/
