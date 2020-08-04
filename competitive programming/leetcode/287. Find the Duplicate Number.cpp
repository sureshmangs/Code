Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.









class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])]<0) return abs(nums[i]);
            nums[abs(nums[i])]=-nums[abs(nums[i])];
        }
        return -1;
    }
};









class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int tmp=0;

        for(int i=0;i<n;i++){
            tmp^=nums[i];
        }

        for(int i=1;i<n;i++)   // as size is n+1
            tmp^=i;


        return tmp;
    }
};









// Slow and Fast pointer technique (will also work for negatives)
// D = distance from start till starting of loop
//  K = distance start of loop till both pointers meet
//   C = length of loop
//   i, j   distance covered in loops by fast and slow pointer
// distance covered by slow, N = D + K + C * i
// distance covered by fast, 2N = D + K + C * j
// subtracting we get D = C(j - 2*i ) - K
// Place slow to start again, it covers D distance to reach start of loop
//  Lets say fast makes x loops and still remains on the colliding position and now
// if he has to reach the start of the loop he hast to go K steps backward

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<=0) return -1;
        int slow=nums[0], fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
