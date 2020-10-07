Given an integer n, add a dot (".") as the thousands separator and return it in string format.



Example 1:

Input: n = 987
Output: "987"
Example 2:

Input: n = 1234
Output: "1.234"
Example 3:

Input: n = 123456789
Output: "123.456.789"
Example 4:

Input: n = 0
Output: "0"


Constraints:

0 <= n < 2^31







class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        if(n==0){
            res+="0";
            return res;
        }
        int i=0;
        while(n){
            int tmp=n%10;
            if(i && i%3==0){
                res="."+res;
                res=to_string(tmp)+res;
            }
            else res=to_string(tmp)+res;
            n/=10;
            i++;
        }

        return res;
    }
};
