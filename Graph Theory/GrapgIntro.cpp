#include<bits/stdc++.h>
using namespace std;

//A simple Representation Of graph using Adjacency List

void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int Vertex) {
	for (int v = 0; v < Vertex ; v++) {
		cout << "Adjacency List of Vertex "
		     << "\n head" << "(" << v << ")";
		for (auto x : adj[v])
			cout << "-->" << x;
		cout << "\n";
	}
}


int main() {
	int vertex = 5;
	vector<int> adj[vertex];
	//Draw Graph For Understanding Purpose
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 3);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 5);
	addEdge(adj, 3, 5);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);
	printGraph(adj, vertex);
	return 0;
}


/* Output

Adjacency List of Vertex
 head(0)-->1-->3-->4
Adjacency List of Vertex
 head(1)-->0-->2-->4
Adjacency List of Vertex
 head(2)-->1-->3-->4-->5
Adjacency List of Vertex
 head(3)-->0-->2-->5-->4
Adjacency List of Vertex
 head(4)-->0-->1-->2-->3-->5

 */