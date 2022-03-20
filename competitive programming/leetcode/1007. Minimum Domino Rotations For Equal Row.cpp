In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino.
 (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6









/* solution 1 */
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX, n = tops.size();
        
        for (int i = 1; i <= 6; i++) {
            int rotate = 0;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (tops[j] == i) continue;
                else if (bottoms[j] == i) rotate++;
                else {
                    flag = false; break;
                }
            }
            if (flag) res = min(res, rotate);
        }
        
        for (int i = 1; i <= 6; i++) {
            int rotate = 0;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (bottoms[j] == i) continue;
                else if (tops[j] == i) rotate++;
                else {
                    flag = false; break;
                }
            }
            if (flag) res = min(res, rotate);
        }
        
        if (res == INT_MAX) res = -1;
        
        return res;
    }
};			









/* soution 2 */
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX, n = tops.size();
        vector <int> counta(7, 0), countb(7, 0), same(7, 0);
        
        for (int i = 0; i < n; i++) {
            counta[tops[i]]++;
            countb[bottoms[i]]++;
            
            if (tops[i] == bottoms[i]) same[tops[i]]++;
        }
        
        for (int i = 1; i < 7; i++) {
            if ((counta[i] + countb[i] - same[i]) == n) 
                res = min(res, n - max(counta[i], countb[i]));
        }
        
        if (res == INT_MAX) res = -1;
        
        return res;
    }
};
