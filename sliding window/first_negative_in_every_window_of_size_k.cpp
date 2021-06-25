/*
Given an array A[] of size N and a positive integer K, 
find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
1 <= A[i] <= 105
1 <= K <= N
*/




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    vector <long long> res;
    
    int start = 0, end = 0;
    
    queue <long long> q;
    
    while (end < n) {
        if (arr[end] < 0) q.push(arr[end]);
        
        if (end - start + 1 < k) end++;
        else if (end - start + 1 == k) {
            if (q.empty()) res.push_back(0);
            else {
                res.push_back(q.front());
                if (q.front() == arr[start]) {
                    q.pop();
                }
            }
            start++;
            end++;
        }
    }
       return res;                                          
 }
