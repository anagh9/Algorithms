//Dfs Traversal Shortest Code in length

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>adj[10000];
bool v[1000];


void DFS(int src) {
	v[src] = 1;
	cout << src << " ";
	for (int i : adj[src]) {
		if (!v[i]) 		//(v[i] == 0)
			DFS(i);
	}
}


int addEgde(int src, int dest) {
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

int main() {

	int vertex = 5;
	addEgde(1, 2);
	addEgde(1, 4);
	addEgde(2, 3);
	addEgde(3, 4);
	addEgde(4, 5);
	addEgde(5, 6);
	addEgde(6, 7);
	DFS(7);
	return 0;
}