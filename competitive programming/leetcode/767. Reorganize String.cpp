Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].







class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        priority_queue<pair<int, char> > pq;   // max heap
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i], char(i+97)});
            }
        }


        string res;
        while(pq.size()>1){
            pair<int, char> cur, next;
            cur=pq.top();
            pq.pop();
            next=pq.top();
            pq.pop();
            res+=cur.second;
            res+=next.second;
            cur.first-=1;
            next.first-=1;
            if(cur.first>0) pq.push(cur);
            if(next.first>0) pq.push(next);
        }

        if(!pq.empty()){
            pair<int , char> last= pq.top();
            if(last.first>1) return "";
            else res+=last.second;
        }
        return res;
    }
};
