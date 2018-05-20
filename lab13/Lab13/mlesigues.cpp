#include <iostream>
#include <limits.h>

using namespace std;

struct Edge {
	int beginHere;
	int endHere;
	int val;
};

struct Graph {
	int Vals;
	int E;
	Edge *edges;
};

//main func
int main() {
	int verts, edges;
	Graph ggraph;

	cin >> verts;
	cin >> edges;

	ggraph.Vals = verts;
	ggraph.E = edges;
	ggraph.edges = new Edge[ggraph.E];

	for (int i = 0; i < ggraph.E; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		ggraph.edges[i].beginHere = start;
		ggraph.edges[i].endHere = end;
		ggraph.edges[i].val = weight;
	}

	int dist[ggraph.Vals];

	//make every edge to +INF
	for (int i = 0; i < ggraph.Vals; i++) {
		dist[i] = INT_MAX;
	}
	dist[0] = 0;

	for (int i = 0; i < ggraph.Vals; i++) {
		for (int j = 0; j < ggraph.E; j++) {
			int a = ggraph.edges[j].beginHere;
			int b = ggraph.edges[j].endHere;
			if (dist[a] != INT_MAX && dist[a] + ggraph.edges[j].val < dist[b])
				dist[b] = dist[a] + ggraph.edges[j].val;
		}
	}

	//negative cycles
	for (int j = 0; j < ggraph.E; j++) {
		int a = ggraph.edges[j].beginHere;
		int b = ggraph.edges[j].endHere;
		if (dist[a] != INT_MAX && dist[a] + ggraph.edges[j].val < dist[b]) {
			cout << "FALSE" << endl;
			return 0;
		}
	}
	cout << "TRUE" << endl;

	for (int i = 0; i < ggraph.Vals; i++) {
		if (dist[i] == INT_MAX) {
			cout << "INFINITY" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
	return 0;
}
		







	
