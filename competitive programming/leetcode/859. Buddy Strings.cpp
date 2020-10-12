Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


Constraints:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.











class Solution {
public:

    bool isEqual(string &A, string &B){
        int m=A.size();
        for(int i=0;i<m;i++){
            if(A[i]!=B[i]) return false;
        }
        return true;
    }

    bool buddyStrings(string A, string B) {
        int m=A.length();
        int n=B.length();

        if(m!=n) return false;

        int freq[26];
        fill(freq, freq+26, 0);

        for(int i=0;i<m;i++)
            freq[A[i]-'a']++;

        if(isEqual(A, B)){
            for(int i=0;i<26;i++){
                if(freq[i]>=2) return true;
            }
        } else {
            // find first mismatch
            int k;
            for(k=0;k<m;k++){
                if(A[k]!=B[k])
                    break;
            }

            // find the mismatched char of B in A
            for(int i=0;i<m;i++){
                if(A[i]==B[k]){
                    swap(A[i], A[k]);
                    return isEqual(A, B);
                }
            }
        }
        return false;  // control wont reach here
    }
};







class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length()) return false;
        int n=A.length();
        long long diff=0;
        for(int i=0;i<n;i++)
            if(A[i]!=B[i]) diff++;

        if(diff>2) return false;

        vector<long long> fa(26, 0);
        vector<long long> fb(26, 0);

        for(int i=0;i<n;i++){
            fa[A[i]-'a']++;
            fb[B[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(fa[i]!=fb[i]) return false;
        }


        if(diff==0){
            for(int i=0;i<26;i++){
                if(fa[i]>=2) return true;
            }
            return false;
        }

        return true;

    }
};
