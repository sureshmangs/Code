Given two non-negative integers, num1 and num2 represented as string, 
return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large 
integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.







class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.length(), n = num2.length();
        
        int carry = 0, i = m - 1, j = n - 1;
        
        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            
            res += ((sum % 10) + '0');
            
            if (sum >= 10) carry = 1;
            else carry = 0;
            
            i--;
            j--;
        }
        
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            
            res += ((sum % 10) + '0');
            
            if (sum >= 10) carry = 1;
            else carry = 0;
            
            i--;
        }
        
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            
            res += ((sum % 10) + '0');
            
            if (sum >= 10) carry = 1;
            else carry = 0;
            j--;
        }
        
        if (carry) res += '1';
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};









// Better Code
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        
        string res = "";
        
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            
            sum += carry;
            
            res += ((sum % 10) + '0');
            
            if (sum >= 10) carry = 1;
            else carry = 0;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
