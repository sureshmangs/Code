Given a lowercase alphabet string s, 
return the number of palindromic substrings in s.

Constraints

1 = n = 1,000 where n is the length of ss
Example 1
Input
s = "tacocat"
Output
10

Explanation
The palindromic substrings are:

"t"
"a"
"c"
"o"
"c"
"a"
"t"
"coc"
"acoca"
"tacocat"








// TC -> O(n^2)

bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int solve(string s) {
    int n = s.length();
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            if (isPalindrome(s.substr(j, i))) res++;
        }
    }
    return res;
}
