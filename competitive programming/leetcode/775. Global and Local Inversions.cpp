We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.








class Solution {
public:
    int localInv=0, globalInv=0;


void merge(vector<int> &v, int l, int mid, int r){
        int n1=mid-l+1;
        int n2=r-(mid+1)+1;
        vector<int> L(n1);
        vector<int> R(n2);

        for(int i=0;i<n1;i++)
            L[i]=v[l+i];
        for(int j=0;j<n2;j++)
            R[j]=v[mid+1+j];

        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                v[k]=L[i];
                i++;
            } else {
                v[k]=R[j];
                j++;
                globalInv+=n1-i;
            }
            k++;
        }

        while(i<n1){
            v[k]=L[i];
            i++;
            k++;
        }

        while(j<n2){
            v[k]=R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int> &v, int l, int r){
        if(l<r){
            int mid=l+(r-l)/2;
            mergeSort(v, l, mid);
            mergeSort(v, mid+1, r);
            merge(v, l, mid, r);
        }
    }

    bool isIdealPermutation(vector<int>& v) {

        // cal local inv
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]) localInv++;
        }

        // cal global inv

        mergeSort(v, 0, n-1);

        if(localInv==globalInv) return true;
        else return false;

    }
};
