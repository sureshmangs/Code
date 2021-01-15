/*
You will be given a square matrix M and a positive integer power N. You will have to compute M raised to the power N. (that is, M multiplied with itself N times.)

Input
First line of input is T ( number of test-cases) First line of each test-case contains two integer M , N where M is size of square matrix that we have to exponent and N is the power to which we have to exponent 
Next M lines describe the input matrix. Each line contains exactly M elements corresponding to each array

Output
Output M line corresponding to each row of resultant matrix Each line must have M integers where jth element of ith line is jth element of resultant matrix taken modulo with 1000000007 (10^9+7).

Simply , you have to print the resultant square matrix.

Example
Input:
2
2 3
1 0 
1 1 
3 3
1 0 4 
1 2 2 
0 4 4 

Output:
1 0 
3 1 
17 112 116 
15 88 100 
28 144 160 

constraints:

1<=T<=10

 1<=M<=50

1<=N<=100000

0<=each element of input matrix<=10^9
*/




#include<bits/stdc++.h>
using namespace std;

#define MAX 51
#define mod 1000000007

void display (long long a[][MAX], int size) {
	 for (int i = 0; i < size; i++) {
    	for (int j = 0; j < size; j++) {
    		cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void multiply (long long a[][MAX], long long b[][MAX], int size) {
	long long mul[MAX][MAX];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mul[i][j] = 0;
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				mul[i][j] = (mul[i][j] % mod + (a[i][k] * b[k][j]) % mod) % mod;
			}
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b[i][j] = mul[i][j];
		}
	}
}

void matrixExponentiation (long long a[][MAX], long long res[][MAX], int n, int size) {
	while (n) {
		if (n % 2 != 0)	multiply(a, res, size);
		
		multiply(a, a, size);
		
		n /= 2;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
    	int m, n;
	    cin >> m >> n;
	    
	    long long a[MAX][MAX];
	    
	    for (int i = 0; i < m; i++) {
	    	for (int j = 0; j < m; j++) {
	    		cin >> a[i][j];
			}
		}
		
		long long res[MAX][MAX];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (i == j) res[i][j] = 1;
				else res[i][j] = 0;
			}
		}
		
		matrixExponentiation(a, res, n, m);
		
		display(res, m);
	}

    return 0;
}
