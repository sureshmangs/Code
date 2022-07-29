Given two strings a and b that represent binary numbers, 
add them and return their sum, also as a string.

The input strings are guaranteed to be non-empty and contain only 1s and 0s.

Constraints

n = 100,000 where n is the length of a
m = 100,000 where m is the length of b
Example 1
Input
a = "1"
b = "1"
Output
"10"
Example 2
Input
a = "111"
b = "1"
Output
"1000"












// TC -> O(max(m,n)), where m = length of string a, and n = length of string b
// SC -> O(1) We use just constant auxiliary space.

string solve(string a, string b) {
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    string addition = "";

    while (i >= 0 || j >= 0) {
        int sum = 0;
        if (i >= 0) sum += (a[i--] - '0');
        if (j >= 0) sum += (b[j--] - '0');
        sum += carry;

        addition += ((sum % 2) + '0');
        carry = sum / 2;
    }

    if (carry) {
        addition += '1';
    }

    reverse(addition.begin(), addition.end());

    // remove starting zeros
    if (addition.length() > 1) {
        int k;
        for (k = 0; k < addition.length(); k++) {
            if (addition[k] != '0') break;
        }
        addition = addition.substr(k);
    }
    
    return addition;
}
