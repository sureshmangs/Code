/*
Given two integers ‘a’ and ‘m’. 
The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’.

 

Example 1:

Input:
a = 3
m = 11
Output: 4
Explanation: Since (4*3) mod 11 = 1, 4 
is modulo inverse of 3. One might think,
15 also as a valid output as "(15*3)
mod 11"  is also 1, but 15 is not in 
ring {0, 1, 2, ... 10}, so not valid.
 

Example 2:

Input:
a = 10
m = 17
Output: 12
Explanation: Since (12*10) mod 17 = 1,
12 is the modulo inverse of 10.
 


 

Expected Time Complexity : O(m)
Expected Auxilliary Space : O(1)

 

Constraints:
1 <= a <= 104
1 <= m <= 104
*/






int extendedEuclid(int a, int b, int &x, int &y) {
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = extendedEuclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}
 
 
 // finding modular multiplicative inverse
   
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclid(a, m, x, y);
        
    if (gcd != 1) return -1;
        
    if (x < 0) x += m;
        
    if (x == 0) return -1;
        
    return x;  // modular multiplicative inverse
}




/*
Using extended euclidean algorithm
As seen above, x and y are results for inputs a and b,
   a.x + b.y = gcd                      ----(1)

And x1 and y1 are results for inputs b%a and a
   (b%a).x1 + a.y1 = gcd

When we put b%a = (b - (âŒŠb/aâŒ‹).a) in above,
we get following. Note that âŒŠb/aâŒ‹ is floor(b/a)

   (b - (âŒŠb/aâŒ‹).a).x1 + a.y1  = gcd

Above equation can also be written as below
   b.x1 + a.(y1 - (âŒŠb/aâŒ‹).x1) = gcd      ---(2)

After comparing coefficients of 'a' and 'b' in (1) and
(2), we get following
   x = y1 - âŒŠb/aâŒ‹ * x1
   y = x1

*/







// finding modular multiplicative inverse using Fermat's little theorem
// a^{p - 2} = a^{-1} (modp)

int power(int x, int y, int m) {
    long long res = 1;
        
    while (y) {
    	if (y % 2) res = (res * x) % m;
            
    	x = (x * x) % m;
        y /= 2;
    }
    return res;
}
    
int modInverse(int a, int m)
{
    int gcd = __gcd(a, m);
        
    if (gcd != 1) return -1;
        
    return power(a, m - 2, m) % m;
        
}
