/*
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
*/



#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int lps[]){
    // length of the previous longest prefix suffix
    int len=0;
    int i=1;
    lps[0]=0;
    int m=pat.length();

    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        } else { // (pat[i] != pat[len])
            if(len!=0){
                len=lps[len-1];
            } else {   // len==0
                lps[i]=0;
                i++;
            }

        }
    }
}

void kmp(string txt, string pat){
    int m=pat.length();
    int n=txt.length();
    int lps[m];
    computeLPS(pat, lps);

    int i=0;    // index for txt
    int j=0;    // index for pat

    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1];
        }
        // mismatch after j matches
        else if(i<n && pat[j]!=txt[i]){
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if(j!=0)
                j=lps[j-1];
            else i++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string txt, pat;
        cin>>txt>>pat;
        kmp(txt, pat);
    }


return 0;
}
