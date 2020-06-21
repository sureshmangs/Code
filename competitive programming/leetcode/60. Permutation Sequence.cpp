
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"





class Solution {
public:
    vector<int> fact, digit;

    void solve(int n, int  k, string &res){
        if(n==1){
            res.push_back(digit[0]+'0');
            return;
        }

        int index=k/fact[n-1];
        if((k%fact[n-1])==0) index-=1;     // boundary case

        res.push_back(digit[index]+'0');    // add digit to index
        digit.erase(digit.begin()+index);    // remove used number
        k-=fact[n-1]*index;
        solve(n-1, k, res);
    }

    string getPermutation(int n, int k) {
        string res;
        if(n==0) return res;

        fact.push_back(1);   // 0!=1
        for(int i=1;i<=n;i++)
            fact.push_back(fact[i-1]*i);

        for(int i=1;i<=n;i++)
            digit.push_back(i);

        solve(n, k, res);

        return res;
    }
};
