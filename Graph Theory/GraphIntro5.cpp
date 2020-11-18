//Bfs Traversal of Graph

#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>

class Graph {
	map<T, list<T> > l;

public:
	void addEdge(T, T);
	void BFS(T);
};

template<class T>
void Graph<T>::addEdge(T src, T dest) {
	l[src].push_back(dest);
	l[dest].push_back(src);
}

template<class T>
void Graph<T>::BFS(T start) {
	map<T, int> visited;
	queue<T> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		T node = q.front();
		q.pop();

		cout << node << " ";

		for (int nbr : l[node]) {
			if (!visited[nbr]) {
				q.push(nbr);
				//Mark that nbr is visited
				visited[nbr] = true;
			}
		}
	}

}




int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.BFS(0);




	return 0;
}

/****

Output :
0 1 2 3 4 5

***/