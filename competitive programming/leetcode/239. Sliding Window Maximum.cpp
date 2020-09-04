Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
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


Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length









class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        deque<int> q;

        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back(); // Remove from rear

            q.push_back(i); // Add new element at rear of queue
        }

        for(int i=k;i<n;i++){
            res.push_back(nums[q.front()]);

            // Remove the elements which are out of this window
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();

            while(!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back(); // Remove from rear

            q.push_back(i);
        }
        // Adding maximum element of last window
        res.push_back(nums[q.front()]);

        return res;
    }
};
