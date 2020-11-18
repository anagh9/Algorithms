//Adjacency Matrix Representation in C++

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	bool **adjMatrix;
	int numVertices;
public:
	void addEdge(int , int);
	void printGraph();
	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjMatrix = new bool*[numVertices];
		for (int i = 0; i < numVertices; i++) {
			adjMatrix[i] = new bool[numVertices];
			for (int j = 0; j < numVertices; j++) {
				adjMatrix[i][j] = false;
			}
		}
	}
};

//Add Edge
void Graph::addEdge(int src, int dest) {
	adjMatrix[src][dest] = true;
	adjMatrix[dest][src] = true;
}

//Print the Matrix

void Graph::printGraph() {
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}


int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);

	g.printGraph();
}

/*** Output

0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0

***/
