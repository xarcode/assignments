#include<iostream>
#include<queue>
#define MAXSIZE 20
using namespace std;

struct AdjListNode{
	int vertex;
	AdjListNode *next;
}; 

struct AdjList{
	AdjListNode *head;
};

class Graph{
	private:
		int V;
		AdjList *arr;
		queue<int> q;
		bool visited[MAXSIZE];
	public:
		Graph(int V){
			this->V=V;
			arr=new AdjList[V];
			for(int i=0;i<V;i++){
				arr[i].head=NULL;
			}
		}
		
	    void addEdge(int src,int dest){
	    	AdjListNode *nn=new AdjListNode;
	    	nn->vertex=dest;
	    	nn->next=NULL;
	    	
	    	nn->next=arr[src].head;
	    	arr[src].head=nn;
	    	
	    	nn=new AdjListNode;
	    	nn->vertex=src;
	    	nn->next=NULL;
	    	
	    	nn->next=arr[dest].head;
	    	arr[dest].head=nn;
		}
		
		void bfs(int v){
			for (int i = 0; i < V; i++) {
        visited[i] = false;}
			q.push(v);
			visited[v] = true;
			while(!q.empty()){
				v = q.front();
				cout << v << " | ";
				q.pop();
				AdjListNode *w=new AdjListNode;
				for(w=arr[v].head;w!=NULL;w=w->next){
					if(!visited[w->vertex]){
						visited[w->vertex]=true;
						q.push(w->vertex);
					}
				}
			}
			
		}
		
		void dfs(int v){
			visited[v]=true;
			AdjListNode *w=new AdjListNode;
			for(w=arr[v].head;w!=NULL;w=w->next)
					if(!visited[w->vertex])
					dfs(w->vertex);
			
		}
		
		void printGraph(){
			for(int v=0;v<V;v++){
				AdjListNode *tmp=arr[v].head;
				cout<<"\nAdjacency list of vertex"<<v<<"\nhead";
				while(tmp){
					cout<<"->"<<tmp->vertex;
					tmp=tmp->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

//	cout << "DFS Traversal from source 2: ";
//	g.dfs(0);
	cout << endl;
	cout << "BFS Traversal from source 2: ";
	
	g.bfs(2);
	return 0;
}
//int main(){
//	int vertices,edges,v1,v2;
//	
//   cout << "\nPlease enter the number of vertices and edges : ";
//   cin >> vertices >> edges;
//   Graph g(vertices);
//   cout << "\nEnter the egdes : ";
//   for(int i=1;i<=edges;i++){
//   	cin>>v1>>v2;
//   	g.addEdge(v1,v2);
//   	
//   }
//   
//   g.printGraph();
//   g.bfs();
//   
//}
