/*
Given an array of integers Arr of size N and a number K.
 Return the maximum sum of a subarray of size K.

 

Example 1:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
 

Example 2:

Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3  
+ Arr4 =1000,
which is maximum.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 


Constraints:
1<=N<=105
1<=K<=N
*/

class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        int start = 0, end = 0;
        long long sum = 0, res = INT_MIN;
        
        while (end < n) {
            sum += arr[end];
            
            if (end - start + 1 < k) end++;
            else if (end - start + 1 == k) {
                res = max(res, sum);
                sum -= arr[start];
                start++;
                end++;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends
