/*
Steps
1) Initialize keys of all vertices as infinite and
   parent of every vertex as -1.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or
   key) is used used as first item  of pair
   as first item is by default used to compare
   two pairs.

3) Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Ptim's implementation differs from Dijkstra.
   In Dijkstr's algorithm, we didn't need this array as
   distances always increase. We require this array here
   because key value of a processed vertex may decrease
   if not checked.

4) Insert source vertex into pq and make its key as 0.

5) While either pq doesn't become empty
    a) Extract minimum key vertex from pq.
       Let the extracted vertex be u.

    b) Include u in MST using inMST[u] = true.

    c) Loop through all adjacent of u and do
       following for every vertex v.

           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)

               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the pq
               (iv) parent[v] = u

6) Print MST edges using parent array.
*/






#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> iPair;

void adjListGraph(vector<pair<int, int> > adj[], int s, int d, int w){
    // undirected graph
    adj[s].push_back({d, w});
    adj[d].push_back({s, w});
}

void prims(vector<pair<int, int> > adj[], int V){
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;     // min heap
    int src=0;
    vector<int> key(V, INF);         // weights
    vector<int> parent(V, -1);       //  u ----> v  edge then u is parent of v
    vector<bool> inMST(V,false);     //  keep track of vertices included in MST

    pq.push({0, src});      // insert source itself in priority queue
    key[src]=0;             // and initialize its key as 0

    while(!pq.empty()){
        int u=pq.top().second;      // pait< key, vertex>
        pq.pop();
        inMST[u]=true;
        for(auto x: adj[u]){
            int v=x.first;         //  vector<vertex, weight>
            int w=x.second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if(inMST[v]==false && w<key[v]){
                key[v]=w;
                pq.push({key[v], v});
                parent[v]=u;
            }
        }
    }
    cout<<"Edge      Weight"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<"        "<<key[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e;
    cin>>v>>e;
    vector<pair<int, int> > adj[v];
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        adjListGraph(adj,s,d,w);
    }
    prims(adj, v);
}
