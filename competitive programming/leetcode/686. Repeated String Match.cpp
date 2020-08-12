Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.












class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m=A.length();
        int n=B.length();

        int k=n/m +2, cnt=0;
        string s="";
        bool flag=false;
        while(k--){
            cnt++;
            s+=A;
            if(s.find(B)!=string::npos){
                flag=true;
                break;
            }
        }
        return flag ? cnt: -1;
    }
};
