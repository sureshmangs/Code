Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.







class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int alen=a.length(), blen=b.length();
        string res="";
        while(alen && blen){
            int tmp=a[alen-1]-'0'+b[blen-1]-'0'+carry;

             if(tmp==3){
                carry=1;
                tmp=1;
            } else if(tmp==2){
                carry=1;
                tmp=0;
            }
            else carry=0;

            res.push_back(tmp+'0');
            alen--;
            blen--;
        }
        while(alen){
            int tmp=a[alen-1]-'0'+carry;
            if(tmp==3){
                carry=1;
                tmp=1;
            } else if(tmp==2){
                carry=1;
                tmp=0;
            }
            else carry=0;
            res.push_back(tmp+'0');
            alen--;
        }
        while(blen){
            int tmp=b[blen-1]-'0'+carry;
             if(tmp==3){
                carry=1;
                tmp=1;
            } else if(tmp==2){
                carry=1;
                tmp=0;
            }
            else carry=0;
            res.push_back(tmp+'0');
            blen--;
        }

        if(carry) res.push_back('1');

        reverse(res.begin(), res.end());
        return res;
    }
};
