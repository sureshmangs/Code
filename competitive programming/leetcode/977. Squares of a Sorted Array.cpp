Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.








class Solution {
public:

    static bool comp(int a, int b){
        return abs(a)<abs(b);
    }

    vector<int> sortedSquares(vector<int>& A) {

        sort(A.begin(), A.end(), comp);

        int n=A.size();

        for(int i=0;i<n;i++)
            A[i]=A[i]*A[i];

        return A;
    }
};




// 2 pointer Technique

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n=A.size();

        vector<int> res(n);

        int start=0, end=n-1, k=n-1;

        while(start<=end){
            if(abs(A[start]) >= abs(A[end])){
                res[k]=A[start]*A[start];
                start++;
            } else {
                res[k]=A[end]*A[end];
                end--;
            }
            k--;
        }

        return res;
    }
};
