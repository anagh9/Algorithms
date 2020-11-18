//DFS Traversal Of Unidirected Graph

#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
class Graph {

private:
	int numVertices;
	list<T> *adjLists;
	bool*  visited;
public:
	Graph(T);
	void addEdge(T , T );
	void DFS(T);
};

//Initialize Graph

template<class T>
Graph<T>::Graph(T vertices) {
	numVertices = vertices;
	adjLists = new list<T>[vertices];
	visited = new bool[vertices];
}

//Add Edges
template<class T>
void Graph<T>::addEdge(T src, T dest) {
	adjLists[src].push_front(dest);
	adjLists[dest].push_front(src); //For Directed Remove This Line
}

//DFS Algorithms

template<class T>
void Graph<T>::DFS(T vertex) {
	visited[vertex] = true;
	list<T> adjList = adjLists[vertex];
	cout << vertex << " ";

	list<int>::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i) {
		if (!visited[*i])
			DFS(*i);
	}
}

int main() {

// TestCase 1:
	Graph<int> g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 4);
	g.addEdge(3, 4);

//TestCase 2:
	// Graph g(4);
	// g.addEdge(0, 1);
	// g.addEdge(0, 2);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);

//Test 3:
	// Graph g(7);
	// g.addEdge(0, 4);
	// g.addEdge(0, 3);
	// g.addEdge(0, 1);
	// g.addEdge(1, 6);
	// g.addEdge(1, 5);
	// g.addEdge(1, 2);
	g.DFS(1);



	return 0;
}


/*** Output

1 4 3 2 0
1 2 3 0
1 2 5 6 0 3 4

***/