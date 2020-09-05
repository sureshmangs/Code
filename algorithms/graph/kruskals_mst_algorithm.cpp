#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int src, dst, weight;
};


class DisjointSet {
	unordered_map<int, int> parent;
public:

	void makeSet(int V){
		// create V disjoint sets (one for each vertex)
		for(int i = 0; i < V; i++)
			parent[i] = i;
	}

	// Find the root of the set in which element k belongs
	int Find(int k){
		// if k is root
		if (parent[k] == k)
			return k;

		// recur for parent until we find root
		return Find(parent[k]);
	}

	void Union(int a, int b){
		// find root of the sets in which elements x and y belongs
		int x = Find(a);
		int y = Find(b);

		parent[x] = y;
	}
};


vector<Edge> Kruskals(vector<Edge> edges, int V){
	// stores edges present in MST
	vector<Edge> MST;

	// initialize DisjointSet class
	DisjointSet ds;

	// create singleton set for each element of universe
	ds.makeSet(V);

	// MST contains exactly V-1 edges
	while (MST.size() != V - 1){
		// consider next edge with minimum weight from the graph
		Edge next_edge = edges.back();
		edges.pop_back();

		// find root of the sets to which two endpoint
		// vertices of next_edge belongs
		int x = ds.Find(next_edge.src);
		int y = ds.Find(next_edge.dst);

		// if both endpoints have different parents, they belong to
		// different connected components and can be included in MST
		if (x != y)
		{
			MST.push_back(next_edge);
			ds.Union(x, y);
		}
	}
	return MST;
}


bool comp(Edge a, Edge b){
	return (a.weight > b.weight);
}


int main(){
	vector<Edge> edges {{ 0, 1, 4 }, { 0, 7, 8 }, { 1, 2, 8 }, { 1, 7, 11 }, { 2, 3, 7 }, { 2, 8, 2 }, { 2, 5, 4 }, { 3, 4, 9 }, { 3, 5, 14 }, { 4, 5, 10 }, { 5, 6, 2 }, {6, 7, 1}, {6, 8, 6}, {7, 8, 7} };

	// sort edges by increasing weight
	sort(edges.begin(), edges.end(), comp);

	int V = 9;  // vertices

	// construct graph
	vector<Edge> e = Kruskals(edges, V);

	for (auto &edge: e)
		cout << "(" << edge.src << ", " << edge.dst << ", "
			<< edge.weight << ")" << endl;

	return 0;
}
