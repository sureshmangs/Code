/*
"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters of length n. There is a great number of "QAQ" in the string (Diamond is so cute!).

illustration by 猫屋 https://twitter.com/nekoyaliu
Bort wants to know how many subsequences "QAQ" are in the string Diamond has given. Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.

Input
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.

Examples
inputCopy
QAQAQYSYIOIWIN
outputCopy
4
inputCopy
QAQQQZZYNOIWIN
outputCopy
3
Note
In the first example there are 4 subsequences "QAQ": "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN".


*/







#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();

    int cnt = 0;

    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'Q'){
            for(int j = i + 1; j < n - 1; j++){
                if(s[j] == 'A'){
                    for(int k = j + 1; k < n; k++)
                        if(s[k] == 'Q')
                            cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
