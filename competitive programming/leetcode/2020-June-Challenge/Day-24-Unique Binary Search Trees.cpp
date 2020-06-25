Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3








class Solution {
public:

    long long gcdd(long long a, long long b){
        if(a==0) return b;
        return gcdd(b%a, a);
    }

    long long catalan(int n, int r){
            if(n==0) return 1;
            if(r==0) return 1;
            long long p=1, k=1;
            if(n-r<r) r=n-r;
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

    int numTrees(int x) {
        if(x<=0) return 1;
        return catalan(2*x, x)/(x+1);
    }
};
