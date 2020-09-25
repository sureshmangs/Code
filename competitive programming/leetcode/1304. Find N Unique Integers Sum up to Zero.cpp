Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000








class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int i=1;

        if(n%2!=0){
            res.push_back(0);
            n--;
            while(n){
                res.push_back(i);
                res.push_back(-i);
                i++;
                n-=2;
            }
        } else {
            while(n){
                res.push_back(i);
                res.push_back(-i);
                i++;
                n-=2;
            }
        }

        return res;
    }
};
