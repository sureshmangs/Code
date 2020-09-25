Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5








class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();

        vector<int> res(n);

        int maxi=arr[n-1];

        res[n-1]=-1;

        for(int i=n-2;i>=0;i--){
            res[i]=maxi;
            if(arr[i]>maxi) maxi=arr[i];
        }

        return res;
    }
};
