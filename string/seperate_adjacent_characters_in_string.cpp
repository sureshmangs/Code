/*
Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Examples:

Input: aaabc
Output: abaca

Input: aaabb
Output: ababa

Input: aa
Output: Not Possible

Input: aaaabc
Output: Not Possible
*/





#include<bits/stdc++.h>
using namespace std;

string reOrganise(string s){
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
            if(last.first>1) return "Not Possible";
            else res+=last.second;
        }
        return res;
}

int main(){
    string s;
    cin>>s;
    cout<<reOrganise(s);
}
