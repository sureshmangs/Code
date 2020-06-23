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

    int gcdd(int a, int b){
        if(b==0) return a;
        return gcdd(b, a%b);
    }

    int NCR(int n, int r){
        if(n==0) return 1;
        if(r==0) return 1;
        if(n-r<r) r=n-r;
        long long p=1, k=1;
        while(r){
            p*=n;
            k*=r;
            int gcd=gcdd(p, k);
            p/=gcd;
            k/=gcd;
            n--;
            r--;
        }
        return p/k;
    }

    vector<int> getRow(int n) { // works fine till n<=33
        vector<int> res;
        for(int i=0;i<=n;i++){
            int val=NCR(n, i);
            res.push_back(val);
        }
        return res;
    }
};
