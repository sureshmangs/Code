Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the 
number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.






class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++){
            int cnt=0, n=i;
            while(n){
                n = n & (n-1);
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};



/*
For a single n
Let, n = 5 , count = 0
n & (n-1) = 5 & 4 = 4  , count =1
n & (n-1) = 4 & 3 = 0  , count = 2

Complexity: O(K), where K is the number of ones present in the binary form of the given number.
*/







// Optimized Approach

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num);
        res.push_back(0);  // for num=0
        if(num==0) return res;

        for(int i=1;i<=num;i++){
            if(i%2==0){
                res[i]=res[i/2];
            } else {
                res[i]=res[i-1]+1;
            }
        }
        return res;
    }
};


/*
Solution considering odd/even status of the number:
In this solution, we can think about if the number if even or odd.
If the number is even, the number of 1s equal to the number which is half of it.
For e.g., the number 8 has the same 1s as the number 4.
The number 10 has the same amount of 1 bits as number 5.
That is because number i is just left shift by 1 bit from number i / 2.
Therefore, they should have the same number of 1 bits.

For the number as odd, e.g. 1, 3, 5, 7.
The number of 1 bits is equal to the number (i - 1) plus 1.
For e.g., for number 3, the number of 1 bits equals to the number 2 plus 1.
For number 11, it equals to number 10 + 1.

source: http://buttercola.blogspot.com/2016/06/leetcode-338-counting-bits.html
*/



/* another approach */

class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> res(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            if (i % 2) res[i] = res[i / 2] + 1;
            else res[i] = res[i / 2];
        }
        
        return res;
    }
};
