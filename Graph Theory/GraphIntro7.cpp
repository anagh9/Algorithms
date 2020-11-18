//Bellman Ford Algorithm

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct edge {
	int s, d, w; // source, destination , weight
};

int bellmanFord(int n, int e, int src, vector<edge> & edge, vector<int> &dist) {
	int s, d, w;
	int i, j;
	i = src;
	dist[i - 1] = 0;

	//n-1 passes
	for (i = 1; i < n; i++) {
		//For each edge
		for (j = 0; j < e; j++) {
			s = edge[j].s;
			d = edge[j].d;
			w = edge[j].w;

			//If w can get a smaller value of dist[d] using egde , replace it
			if (dist[s] != INT_MAX && dist[s] + w < dist[d]) {
				dist[d] = dist[s] + w;
			}
		}
	}

	//This loop will detect negative loop
	for (j = 0; j < e; j++) {
		s = edge[i].s;
		d = edge[i].d;
		w = edge[i].w;

		if (dist[s] != INT_MAX && dist[s] + w < dist[d]) {
			//We have caught a negative loop
			return 0;
		}

	}

	//All okay Indicating no negative loop
	return 1;
}



int main() {
	cout << "Enter the no. of verties ";
	int n; cin >> n;
	cout << "Enter no. of edges ";
	int e; cin >> e;
	vector<edge> edge(e);
	cout << "Enter the src, dest and weight of each edge" << endl;
	int s, d, w ; // Source , dest , weight
	for (int i = 0; i < e; i++) {
		cin >> s >> d >> edge[i].w;
		edge[i].s = s - 1;
		edge[i].d = d - 1;
	}

	cout << "Enter Source vertex : ";
	int src ; cin >> src;

//Create a vector of size n (for n vertices) and Initialize the value of each element to Infinity
//dist[i] = The minimum distance of vertex i from source vertex
	vector<int> dist(n, INT_MAX);

	int x = bellmanFord(n, e, src, edge, dist);

	cout << endl;
	if (x) {
		cout << "Vertex Min. distance from Source" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " " << dist[i] << endl;
		}
	}

	else {
		//negative loop
		cout << "There is negative weight loop in the graph : " << endl;

	}

	return 0;
}


/**

Enter the no. of verties 5
Enter no. of edges 7
Enter the src, dest and weight of each edge
1 2 17
2 3 25
3 4 1
4 2 -24
2 5 15
1 4 40
5 3 9
Enter Source vertex : 1

Vertex Min. distance from Source
1 0
2 16
3 40
4 40
5 31

**/