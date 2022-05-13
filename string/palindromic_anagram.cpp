Given a string s, determine whether any anagram of s is a palindrome.

Constraints

n = 100,000 where n is the length of s
Example 1
Input
s = "carrace"
Output
true
Explanation
"carrace" should return true, since it can be rearranged to form "racecar", which is a palindrome.











bool solve(string s) {
    unordered_map <char, int> m;
    for (auto &x: s) m[x]++;

    int odd = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second % 2) odd++;
    }

    return odd <= 1;
}
