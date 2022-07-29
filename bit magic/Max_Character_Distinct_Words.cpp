Given a list of lowercase alphabetical strings words, 
return the maximum sum of the lengths of two distinct words that don't share a common letter.

Constraints

n = 1,000 where n is the length of words
w = 1,000 where w is the length of the longest string in words
Example 1
Input
words = ["abcde", "xyz", "abdexyz", "axyz"]
Output
8
Explanation
These two words don't share any common letters ["abcde", "xyz"]










// Brute Force (TLE)

int solve(vector<string>& words) {
    int sum = 0;

    for (int i = 0; i < words.size(); i++) {
        unordered_map <char, bool> freq;
        for (auto &x: words[i]) freq[x] = true;

        for (int j = i + 1; j < words.size(); j++) {
            bool same = false;
            for (auto &x: words[j]) {
                if (freq[x]) {
                    same = true; break;
                }
            }
            if (!same) {
                int tmpSum = words[i].length() + words[j].length();
                sum = max(sum, tmpSum);
            }
        }
    }
    return sum;
}









// Bitmasking (Accepted)

int getBitValue(string word) {
    int value = 0;
    for (auto &c: word) {
        int j = (c - 'a');
        value = value | (1 << j);
    }
    return value;
}

int solve(vector<string>& words) {
    int sum = 0, n = words.size();
    vector <int> bitRepresentation;

    for (auto &word: words) {
        bitRepresentation.push_back(getBitValue(word));
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (int(bitRepresentation[i] & bitRepresentation[j]) == 0) {
                int tmpSum = words[i].length() + words[j].length();
                sum = max(sum, tmpSum);
            }
        }
    }
    return sum;
}
