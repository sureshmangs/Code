You are visiting a farm that has a single row of fruit trees arranged from left to right.
The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible.
However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit.
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree
(including the start tree) while moving to the right.

The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

Constraints:
1 <= fruits.length <= 10^5
0 <= fruits[i] < fruits.length
********************************************************************************










# Approach 1: Sliding Window

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        int start = 0, end = 0; 	// start and end of the sliding window
        int k = 2; 	// only two baskets available

        unordered_map <int, int> freq;
        
        while (end < tree.size()) {
            freq[tree[end]]++;
            
            if (freq.size() <= k) res = max(res, end - start + 1);
            
            if (freq.size() > k) {
                freq[tree[start]]--;
                if (freq[tree[start]] == 0) freq.erase(tree[start]);
                start++;	// slide the window
            }
            end++;  // increment window size
        }

        return res;
    }
};

TC -> O(n), n is the size of vector tree
SC -> O(1)
