Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.













class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend <= INT_MIN && divisor == -1) return INT_MAX;
        return dividend/divisor;
    }
};





class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n=dividend, m=divisor;
        if(n <= INT_MIN && m == -1) return INT_MAX;

        int sign = (n < 0) ^ (m < 0) ? -1: 1;

        n=abs(n);
        m=abs(m);

        long long q=0, temp=0;

        for(int i=31; i>=0; i--){
            if(temp + (m << i) <= n){
                temp += m << i;
                q += 1 << i;     // q |= 1 << i;
            }
        }
        return sign * q;
    }
};


/*
dividend = quotient * divisor + remainder
dividend -  quotient * divisor  >= 0
So here we find highest value of quotient
We start with highest value of i  ie:  (divisor * 2^31) .... (divisor * 2^30)..................(divisor * 2^0)
here (m << i) is equivalent to m * 2^i
we keep adding (1 << i) or in other words 2^i to quotient
*/


