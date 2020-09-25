Share
Given an array of numbers arr. A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.



Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


Constraints:

2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6








class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();

        if(n<=2) return true;

        sort(arr.begin(), arr.end());

        int cd=arr[1]-arr[0];

        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i] != cd)
                return false;
        }

        return true;
    }
};



//  O(n)

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();

        if(n<=2) return true;

        int maxi=*max_element(arr.begin(), arr.end());
        int mini=*min_element(arr.begin(), arr.end());


        if((maxi-mini)%(n-1)!=0) return false;

        int diff=(maxi-mini)/(n-1);

        int start=0;

        while(start<n){
            if(arr[start]==mini+start*diff) start++;
            else if((arr[start]-mini)%diff!=0) return false;
            else {
                int pos=(arr[start]-mini)/diff;
                if(pos<0 || arr[start]==arr[pos]) return false;
                else swap(arr[start], arr[pos]);
            }
        }


        return true;
    }
};


/*
AP = a, a + d, a + 2d, . . . , a + (n - 1)d
T1 = a - first term of AP also min value in AP for d > 0
Tn = a + (n - 1)d - nth term of AP also the max value in AP for d > 0

Tn - T1 = (n - 1)d => d = (max(arr) - min(arr)) / (n - 1) common difference of our AP.

Maximum and minimum are first and last elements of the progression. Using this fact we find the difference. Then we rearrange the elements in the input array.
The goal of the second loop is to reorder elements in such a way that arr[i] = min + i * d (if this is impossible false must be returned).

Source: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/720152/O(n)-time-O(1)-space
