#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void bellmanFord(vector<vector<int> > &edges, int v, int src){
    int e=edges.size();
    vector<int> dist(v, INF);

    dist[src]=0;

    for(int i=1;i<=v-1;i++){
        for(int j=0;j<e;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];

            if(dist[v]>dist[u]+w)
                dist[v]=dist[u]+w;
        }
    }

    //If we get a shorter path, then there is a cycle.
    for(int j=0;j<e;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];

        if(dist[u]!=INF && dist[v]>dist[u]+w){
            cout<<"Graph contains negative weight cycle"<<endl;
            return;
        }

    }

    cout<<"Vertex  Distance"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"          "<<dist[i]<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v=5;
    vector<vector<int> > edges { { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 }, { 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 } };  // u, v, w
    bellmanFord(edges, v, 0);  // <edges, v, source>
}



// Time Complexity: O(VE)
