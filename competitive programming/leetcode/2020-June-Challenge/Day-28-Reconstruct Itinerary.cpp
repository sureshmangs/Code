Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
But it is larger in lexical order.










class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string> > adj;
        vector<string> res;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> s;
        s.push("JFK");

        while(!s.empty()){
            string src=s.top();
            if(adj[src].size()==0){ // no further travel possible
                res.push_back(src);
                s.pop();
            } else {
                auto dst=adj[src].begin();
                s.push(*dst);
                adj[src].erase(dst);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};



