/*
You're given three numbers: , , and , and all you have to do is to find the number  where
As the number can be very large, output it modulo .

Consider the following link: http://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form

Input Format

First line contains a single integer  - the number of tests.  lines follow, each containing three integers: ,  and .

Constraints



Output Format

For each test case output a single integer  .

Sample Input

8  
2 3 1  
9 1 7  
9 8 3  
2 4 9  
1 7 2  
1 8 1  
4 3 1  
3 7 5  
Sample Output

3  
85  
25  
178  
8  
8  
3  
44
*/





#include<bits/stdc++.h>
using namespace std;

#define MAX 2
#define mod 1000000007


void multiply (long long A[][MAX], long long b[][MAX], long long size) {
    long long mul[MAX][MAX];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mul[i][j] = 0;
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                mul[i][j] = (mul[i][j] % mod + (A[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            b[i][j] = mul[i][j];
        }
    }
}

void matrixExponentiation (long long A[][MAX], long long res[][MAX], long long n, long long size) {
    while (n) {
        if (n % 2 != 0)    multiply(A, res, size);
        
        multiply(A, A, size);
        
        n /= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        
        long long A[MAX][MAX];
        
        A[0][0] = 0;
        A[0][1] = 1;
        A[1][0] = 1;
        A[1][1] = 1;
        
        long long res[MAX][MAX];
        
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (i == j) res[i][j] = 1;
                else res[i][j] = 0;
            }
        }
        
        if (n == 0) cout << a << endl;
        else if (n == 1) cout << b << endl;
        else {
            matrixExponentiation(A, res, n, MAX);
            cout << ((a * res[0][0]) % mod + (b * res[1][0]) % mod) % mod << endl;
        }
        

    }

    return 0;
}

