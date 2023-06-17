You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Constraints:
1 <= nums.length <= 10^5
-104 <= nums[i] <= 10^4
1 <= k <= nums.length
********************************************************************************










# Approach 1: Monotonic queue (deque)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> maxi;
        
        int start = 0, end = 0; // start and end of the sliding window

        while (end < nums.size()) {
            while (!maxi.empty() && maxi.back() < nums[end]) {
                    maxi.pop_back();
            }
            maxi.push_back(nums[end]);
            
            if (end - start + 1 == k) { // windows complete
                res.push_back(maxi.front());
                if (maxi.front() == nums[start])  maxi.pop_front();
                start++;
            }
            end++;  // increment window size
        }
        return res;
    }
};

TC -> O(n), n is the size of nums
SC -> O(k), k is the window size, we store maximum k elements in the deque










# Approach 2: Max Heap (priority queue)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq; // max heap
        
        int start = 0, end = 0; // start and end of the sliding window

        while (end < nums.size()) {
            pq.push({nums[end], end});
            
            if (end - start + 1 == k) { // windows complete
                res.push_back(pq.top().first);
                while (!pq.empty() && (pq.top().second == start || pq.top().second <= (end - k)))
                    pq.pop();   // remove elements outside the window
                start++;
            }
            end++;  // increment window size
        }
        return res;
    }
};

TC -> O(n * logk), n is the size of nums, k is the window size, logk is the insertion/deletion time of the priority queue
SC -> O(k), k is the window size, we store maximum k elements in the priority queue
