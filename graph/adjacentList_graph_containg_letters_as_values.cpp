// Creating a graph containg letters as values
// same can be done for a graph containg "words" as values, 
// graph containg integer values between 10^(-18) to 10^(18)


#include<bits/stdc++.h>
using namespace std;

void adjListGraph(map <char, vector <char>> &adj, char s, char d){
    // undirected graph
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void showGraph(map <char, vector <char>> adj) {  
    for (auto it = adj.begin(); it != adj.end(); it++) {
        cout << it->first;
        for (auto x : it->second)
            cout << "->" << x;
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e;
    cin >> e;
    
    map <char, vector <char> > adj; 
    
    while (e--){
        char s, d;
        cin >> s >> d;
        adjListGraph(adj, s, d);
    }
    
    showGraph(adj);
}
