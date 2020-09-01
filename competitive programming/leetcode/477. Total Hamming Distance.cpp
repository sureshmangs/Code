The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.














// Brute Force O(n2)

class Solution {
public:

    int getHamming(int x, int y){
        int ham=0;
        int tmp=x^y;
        for(int i=0;i<32;i++){
            ham+=tmp & 1;
            tmp=tmp>>1;
        }
        return ham;
    }

    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res+=getHamming(nums[i], nums[j]);
            }
        }
        return res;
    }
};







// O(n)

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int n=nums.size();

        for(int i=0;i<32;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[j] & (1 << i))
                    cnt++;
            }
            res+=cnt * (n-cnt);
        }
        return res;
    }
};


/*
The total Hamming distance is constructed bit by bit in this approach.

Let's take a series of number: a1, a2, a3,..., an

Just think about all the Least Significant Bit (LSB) of a(k) (1 ≤ k ≤ n).

How many Hamming distance will they bring to the total?

If a pair of number has same LSB, the total distance will get 0.

If a pair of number has different LSB, the total distance will get 1.

For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), and q numbers have 1 for LSB (put in set N).

There are 2 situations:

Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.

Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.

Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2

How many pairs are there in Situation 2?

We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).

The total possibilities is p × q = pq, which means

The total Hamming distance will get pq from LSB.
If we remove the LSB of all numbers (right logical shift), the same idea can be used again and again until all numbers becomes zero


*/




// Source:    https://leetcode.com/problems/total-hamming-distance/discuss/96243/Share-my-O(n)-C%2B%2B-bitwise-solution-with-thinking-process-and-explanation
