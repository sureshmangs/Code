Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.



Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""


Note:

A.length == 4
0 <= A[i] <= 9










class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string res;
        sort(A.begin(), A.end());
        do{
            string hours = to_string(A[0])+to_string(A[1]);
            string minutes = to_string(A[2])+to_string(A[3]);
            if(hours < "24" && minutes < "60") res=hours+":"+minutes;  // sorting helped here

        }while(next_permutation(A.begin(), A.end()));
        return res;
    }
};
