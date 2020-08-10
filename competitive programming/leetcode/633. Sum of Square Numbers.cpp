Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False



class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++){
            // b = sqrt(c - a*a)
            double b = sqrt(c-a*a);
            if(b==int(b)) return true;
        }
        return false;
    }
};

// TC:   sqrt(c)*logc




// Brute force (TLE)
/*
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++){
            for(long long b=0;b*b<=c;b++){
                if(a*a+b*b==c) return true;
            }
        }
        return false;
    }
};
*/
