Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.



Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000






class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n=A.size();

        vector<int> res(n);

        int k=0;

        for(int i=0;i<n;i++){
            if(A[i]%2==0){
                res[k]=A[i];
                k+=2;
            }
        }

        k=1;

        for(int i=0;i<n;i++){
            if(A[i]%2!=0){
                res[k]=A[i];
                k+=2;
            }
        }

        return res;
    }
};






// 2 pointer Solution

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n=A.size();

        for(int i=0,j=1;i<n;i+=2, j+=2){
            while(i<n && A[i]%2==0) i+=2;
            while(j<n && A[j]%2==1) j+=2;

            if(i<n) swap(A[i], A[j]);
        }

        return A;
    }
};

/*
Use two pointers to search for missplaced odd and even elements, and swap them.
for i<n :  half of integers are odd, and half are even". If we cannot find a misplaced even element, there are no misplaced odd ones. Therefore, if i >= A.size(), then j >= A.size() is always true.
*/
