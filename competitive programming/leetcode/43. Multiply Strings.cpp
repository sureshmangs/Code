Given two non-negative integers num1 and num2 represented as strings,
return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
********************************************************************************










# Approach 1:

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int sum = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = (sum % 10) + '0';
                carry = sum / 10;
            }
            res[i] = carry + '0';
        }
        int i = 0;
        while (res[i] == '0' && i < m + n - 1) i++;

        return res.substr(i);
    }
};

TC -> O(m * n), m, n is the length of nums1, nums2
SC -> O(1)
