// Priority Queue Implementation

#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> iPair;

void adjListGraph(vector<pair<int, int> > adj[], int s, int d, int w){
    // undirected graph
    adj[s].push_back({d, w});
    adj[d].push_back({s, w});
}

void dijkstras(vector<pair<int, int> > adj[], int V, int src){
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;     // min heap
    vector<int> dist(V, INF);    // create a vector for distances and initialize all distances as infinite (INF)
    pq.push({0, src});
    dist[src]=0;

    while(!pq.empty()){
        int u=pq.top().second;  // pair<distance, vertex >
        pq.pop();
        for(auto x: adj[u]){
            int v=x.first;     // pair<vertex, weight >
            int w=x.second;

            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<endl;
    cout<<"Vertex  Distance"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"          "<<dist[i]<<endl;
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
    dijkstras(adj, v, 0);    // source is 0
}









/*
Set implementation


#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> iPair;

void adjListGraph(vector<pair<int, int> > adj[], int s, int d, int w){
    // undirected graph
    adj[s].push_back({d, w});
    adj[d].push_back({s, w});
}

void dijkstras(vector<pair<int, int> > adj[], int V,int src){
    set< pair<int, int> > s;

    vector<int> dist(V, INF);

    dist[src] = 0;
    s.insert({dist[src], src});

    while (!s.empty()){
        pair<int, int> tmp = *(s.begin());
        s.erase(s.begin());

        int u = tmp.second;

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;

            if(dist[v] > dist[u] + w){
                if(dist[v] != INF)
                    s.erase(s.find({dist[v], v}));

                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }


    cout<<endl;
    cout<<"Vertex  Distance"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"          "<<dist[i]<<endl;
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
    dijkstras(adj, v, 0);    // source is 0
}



*/
