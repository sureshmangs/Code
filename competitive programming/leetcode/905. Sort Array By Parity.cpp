Given an array A of non-negative integers, return an array consisting of 
all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000







// Without extra space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0, odd = nums.size() - 1;
        
        while (even < odd) {
            if (nums[even] % 2) {
                if(nums[odd] % 2 == 0) {
                    swap(nums[even], nums[odd]);
                }
                odd--;
            } else even++;
        }
        
        return nums;
    }
};






// Extra space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        vector<int> res(n);
        int start=0, last=n-1;
        for(int i=0;i<n;i++){
            if(A[i]%2==0){
                res[start++]=A[i];
            } else {
                res[last--]=A[i];
            }
        }
        return res;
    }
};
