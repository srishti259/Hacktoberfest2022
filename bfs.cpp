#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<list<int>> adj;
	
public:
	Graph(int V); 
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V,false);


	list<int> queue;
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
	
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
	Graph gph(4);
	gph.addEdge(0, 1);
	gph.addEdge(0, 2);
	gph.addEdge(1, 2);
	gph.addEdge(2, 0);
	gph.addEdge(2, 3);
	gph.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	gph.BFS(2);

	return 0;
}
