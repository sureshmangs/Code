Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:

1 is typically treated as an ugly number.
n does not exceed 1690.
   Hide Hint #1
The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
   Hide Hint #2
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
   Hide Hint #3
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
   Hide Hint #4
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).









class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        int i2=0, i3=0, i5=0;
        int nmt2=2, nmt3=3, nmt5=5;  // next multiple
        int nun=1;   // next ugly number
        ugly[0]=1;  // first ugly number
        for(int i=1;i<n;i++){
            nun=min(nmt2, min(nmt3, nmt5));
            ugly[i]=nun;
            if(nun==nmt2){
                i2=i2+1;
                nmt2=ugly[i2]*2;
            }
            if(nun==nmt3){
                i3=i3+1;
                nmt3=ugly[i3]*3;
            }
            if(nun==nmt5){
                i5=i5+1;
                nmt5=ugly[i5]*5;
            }
        }
        return nun;
    }
};

