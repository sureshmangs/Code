We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)








class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum=0;
        if(num<=0) return false;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                if(i!=num/i) sum+=i+num/i;
                else sum+=i;
            }
        }
        return sum-num==num;  // removing the number itself from summation
    }
};

// for n = 16
// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
// 1,16     2,8   4,4   are the factors ie:   i and num/i









/*
/ Alter
class Solution {
public:
    bool checkPerfectNumber(int n) {
        if(n<=0) return false;
        long long sum=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0) sum+=i;
        }
        return sum==n;
    }
};
*/
