#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

void rabinKarp(string pat, string txt, int q){
	int m = pat.length();
	int n = txt.length();
	int i, j;
	int ph = 0; // hash value for pattern
	int th = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, m-1)%q"
	for(i = 0; i < m - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first window of text
	for (i = 0; i < m; i++){
		ph = (d * ph + pat[i]) % q;
		th = (d * th + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= n - m; i++){
		// Check the hash values of current window of text and pattern.
		//If the hash values matches then only we check for characters on by one
		if( ph == th ){
			// Check for characters one by one
			for(j = 0; j < m; j++){
				if (txt[i+j] != pat[j])
					break;
			}

			// if ph == th and pat[0...m-1] = txt[i, i+1, ...i+m-1]
			if (j == m)
				cout<<"Pattern found at index "<< i<<endl;
		}

		// Calculate hash value for next window of text: removing last digit and adding next digit
        th = (d*(th - txt[i]*h) + txt[i+m])%q;

        // We might get negative value of t, converting it to positive
        if(th < 0)
            th = th + q;
	}
}


int main(){
	string txt = "THIS TEXT IS A RANDOM TEXT";
	string pat = "TEXT";
	int q = 101; // A prime number
	rabinKarp(pat, txt, q);
	return 0;
}
