/*
Given a word pat and a text txt. 
Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.
*/




	
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	   int start = 0, end = 0, res = 0, match = 0, k = pat.length();
	   
	   unordered_map <char, int> m;
	   
	   for (auto &x: pat) m[x]++;
	   
	   while (end < txt.length()) {
	       char right = txt[end];
	       if (m.find(right) != m.end()) {
	           m[right]--;
	           if (m[right] == 0) match++;
	           if (match == m.size()) res++;
	       }
	       if (end - start + 1 < k) end++;
	       else if (end - start + 1 == k) {
	           char left = txt[start];
	           if (m.find(left) != m.end()) {
	               if (m[left] == 0) match--;
	               m[left]++;
	           }
	           start++;
	           end++;
	       }
	   }
	   
	   return res;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
