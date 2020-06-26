Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"








class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n>0){
            int ch=n%26;
            if(ch==0){
                s+='Z';
                n=n/26-1;
            }
            else {
                s+=char(ch+'A'-1); // 65 -> A
                n=n/26;
            }

        }
        reverse(s.begin(), s.end());
        return s;
    }
};
