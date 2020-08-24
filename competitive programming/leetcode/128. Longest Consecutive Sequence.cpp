Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.












// TC : O(nlgn)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int res=1, cnt=1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]) continue;
            if(abs(nums[i+1]-nums[i]==1)){
                cnt++;
            } else cnt=1;
            if(cnt>res) res=cnt;
        }
        return res;
    }
};





/*
Brute Force
Considers each number in nums, attempting to count as high as possible from that number using only numbers in nums.
After it counts too high (i.e. currentNum refers to a number that nums does not contain),
it records the length of the sequence if it is larger than the current best.
*/

// TLE
class Solution {
    bool arrayContains(vector<int> nums, int num) {
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == num) {
                return true;
            }
        }
        return false;
    }
    public:
    int longestConsecutive(vector<int> &nums) {
        int longestStreak = 0;

        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }
};





// O(N)

class Solution {
    public:
    int longestConsecutive(vector<int> &nums) {
        int longestStreak = 0;
        set<int> s;
        // Hash all the array elements
        for(int num: nums){
            s.insert(num);
        }

         // check each possible sequence from the start then update optimal length
        for (int num : nums) {
                int currentNum = num;
                int currentStreak = 1;
                 // if current element is the starting element of a sequence
                if(s.find(currentNum-1)==s.end()){
                   // Then check for next elements in the sequence
                    while (s.find(currentNum+1)!=s.end()) {
                        currentNum += 1;
                        currentStreak += 1;
                    }
                }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }
};

