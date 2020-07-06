The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.










class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=32, cnt=0;
        while(n--){
            bool a=x & 1;
            bool b=y & 1;
            if(a!=b) cnt++;
            x=x>>1;
            y=y>>1;
        }
        return cnt;
    }
};









class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=x^y;
        int cnt=0;
        while(res>0){
            cnt+=res & 1;
            res>>=1;
        }
        return cnt;
    }
};
