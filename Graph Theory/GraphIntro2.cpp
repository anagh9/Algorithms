#include<bits/stdc++.h>
#define V 5
using namespace std;


//Adjacency Matrix Representation of directed Graph

//Initialization of Graph
void init(int arr[][V]) {
	for (int i = 0; i < V; i++) {
		for (int j = 0 ; j < V; j++) {
			arr[i][j] = 0;
		}
	}
}

//Add Edge set arr[src][dest] = 1
void addEdge(int arr[][V], int src, int dest) {
	arr[src][dest] = 1;
//  arr[dest][src] = 1;  //For Unidirected Graph

}

void printAdjMartix(int arr[][V]) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << " " << arr[i][j];
		}
		cout << "\n";
	}
}

int main() {
	// int V = 5;
	int adjMatrix[V][V];

	init(adjMatrix);
	addEdge(adjMatrix, 0, 1);
	addEdge(adjMatrix, 0, 2);
	addEdge(adjMatrix, 0, 3);
	addEdge(adjMatrix, 1, 2);
	addEdge(adjMatrix, 2, 3);
	addEdge(adjMatrix, 3, 4);
	addEdge(adjMatrix, 4, 0);

	printAdjMartix(adjMatrix);



	return 0;
}


/* Output

 0 1 1 1 0
 0 0 1 0 0
 0 0 0 1 0
 0 0 0 0 1
 1 0 0 0 0

 */