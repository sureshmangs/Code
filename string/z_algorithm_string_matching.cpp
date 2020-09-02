#include<bits/stdc++.h>
using namespace std;

void z_algo(string str, int Z[]){
	int n = str.length();
	int L, R, idx;

	// [L,R] make a window which matches with prefix of s
	L = R = 0;
	for(int i = 1; i < n; ++i){
		// if i>R nothing matches so we will calculate Z[i] using naive way.
		if(i > R){
			L = R = i;

			// R-L = 0 in starting, so it will start checking from 0'th index.
			// For example, for "ababab" and i = 1, the value of R
			// remains 0 and Z[i] becomes 0.
			//For string "aaaaaa" and i = 1, Z[i] and R become 5
			while (R<n && str[R-L] == str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else {
			// idx = i-L so idx corresponds to number which matches in [L,R] interval
			idx = i-L;

			// if Z[idx] is less than remaining interval
			// then Z[i] will be equal to Z[idx].
			// For example, str = "ababab", i = 3, R = 5
			// and L = 2
			if (i+Z[idx] <= R)
				Z[i] = Z[idx];

			// For example str = "aaaaaa" and i = 2, R is 5, L is 0
			else
			{
				// else start from R and check manually
				L = i;
				while (R<n && str[R-L] == str[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}


int main(){
	string text = "GEEKS FOR GEEKS";
	string pattern = "GEEK";

	string str = pattern + "$" + text;
	int n = str.length();

	int Z[n];   // z array
	z_algo(str, Z); // construct z array

	for(int i = 0; i < n; ++i){
		if (Z[i] == pattern.length())
			cout<<"Pattern found at index "<< i - pattern.length() - 1 << endl;
	}
	return 0;
}
