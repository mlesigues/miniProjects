#include <iostream>
#include <climits>
#include <queue>
#include <list>
#include <vector>
using namespace std;

//Minimum Spanning Tree using Prim's algorithm

typedef pair<int, int> iPair; //intPair ==> int pair

//adjacency list rep
class Graph {
    int vertices;
    
    list< pair <int, int> > *adj; //weighted graph stores vertex and weight pair 
public:
    Graph(int vertices);
    void addEdge(int u, int v, int w);
    void primMST();    
};

Graph::Graph(int vertices) { //allocates memory for the list
    this->vertices = vertices;
    adj = new list<iPair> [vertices];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v,w)); 
    adj[v].push_back(make_pair(u,w));
}

void Graph::primMST() { //shortest paths from source to all other verts	
	//priority queue
	priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

	int source = 0;

  	//vector for keys and set them to +infinity/INT_MAX
	vector<int> key(vertices, INT_MAX);

	//store parent array which store MST
	 vector<int> parent(vertices, -1);

	//keeps track of vertices used
	vector<bool> inMST(vertices, source);
    
    //insert source in priority queue and initialize its key = 0
    pq.push(make_pair(0, source));
    key[source] = 0;

	//check if the priority queue is empty
    while(!pq.empty()) {
        //1st vertex pair == minimum key vertex, we extract
        //vertex label is stored in 2nd pair, and key must be first in the pair
        int u = pq.top().second;
        pq.pop();

        //includes vertex
        inMST[u] = true;

		//iterate through the vector
        list< pair<int, int> > :: iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            //get vertex label and weight of curr adj
            int v = (*it).first;
            int weight = (*it).second;

            //checks if v is in MST and if weight(u,v) is smaller than curr key
            if(inMST[v] == false && key[v] > weight) {
                //update key 
                key[v] = weight;
				pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
       }
    }
    
    //print edges
    for(int i = 1; i < vertices; ++i) {
        cout << parent[i] << endl;
	}
}
 
//main func
int main() {
	int verts;
	int edges;	

	cin >> verts;
	cin >> edges;

	Graph g(verts); //put the inputs to the graph
	int *u = new int[edges];
	int *v = new int[edges];
	int *weight = new int[edges];

	for (int i = 0; i < edges; i++) {
		//now put it on the list
		cin >> u[i];
		cin >> v[i];
		cin >> weight[i];
		//call add edge
		g.addEdge(u[i], v[i], weight[i]);
	}
	//call prim
	g.primMST();
}















