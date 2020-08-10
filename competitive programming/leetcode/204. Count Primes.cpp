Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.












class Solution {
public:
    int countPrimes(int n) {
        bool seive[n+1];
        fill(seive, seive+n+1, true);
        for(int p=2; p*p<=n;p++){
            if(seive[p]==true){
                for(int i=p*p;i<=n;i+=p){
                    seive[i]=false;
                }
            }
        }

        int cnt=0;
        for(int p=2;p<n;p++){ // prime less than n, not including n
            if(seive[p]==true) cnt++;

        }
        return cnt;
    }
};
