#include <iostream>

#define MAXSIZE 10

using namespace std;

class Graph {
public:
	int V;
	bool visited[MAXSIZE];
	int adj[MAXSIZE][MAXSIZE];
	
	Graph(int v = 5){
		V = v;
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++)
				adj[i][j] = 0;
	}

	void addEdge(int v, int w);
	void DFS(int v);
	void BFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v][w] = 1;
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int i = 0; i < V; i++)
		if (!visited[i] and adj[v][i])
			DFS(i);
}

void Graph::BFS(int s)
{
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int queue[V];
    int front = 0, rear = 0;
 
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear) {
        s = queue[front++];
        cout << s << " ";
 
        for (int adjacent = 0; adjacent < V;
             adjacent++) {
            if (adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "DFS Traversal from source 2: ";
	g.DFS(2);
	cout << endl;
	cout << "BFS Traversal from source 2: ";
	g.BFS(2);
	return 0;
}

