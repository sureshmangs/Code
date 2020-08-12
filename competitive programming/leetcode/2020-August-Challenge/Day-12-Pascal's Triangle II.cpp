Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?













class Solution {
public:

    int NCR(int n, int r){
        if(n==0 || r==0) return 1;
        if(n-r<r) r=n-r;
        long long p=1;
        for(int i=1;i<=r;i++){
            p*=n;
            p/=i;
            n--;
        }
        return p;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0;i<=rowIndex;i++){
            res.push_back(NCR(rowIndex, i));
        }
        return res;
    }
};
