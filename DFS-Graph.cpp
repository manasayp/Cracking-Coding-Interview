#include<iostream>
#include<string>
#include<stack>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *dgraph;
public:
	Graph(int v)
	{
		this->V = v;
		dgraph = new list<int>[V];
	}
	~Graph() { delete[] dgraph;}
	void add(int u, int v);
	bool isRoute(int src, int dst);
};

void Graph::add(int u, int v)
{
	dgraph[u].push_back(v);
}

bool Graph::isRoute(int src, int dst)
{
	if(src == dst) return true;
	stack<int> st;
	bool *visited = new bool[V];
	for(int i = 0; i <  V; i++)
		visited[i] = false;
	st.push(src);
	visited[src] = true;
	while(!st.empty())
	{
		int x = st.top(); 
		st.pop();
		if(!visited[x])
			visited[x] = true;
		list<int>::iterator it;
		for(it = dgraph[x].begin(); it != dgraph[x].end(); ++it)
		{
			if(*it == dst) 
				return true;
			if(!visited[*it])
			{
				st.push(*it);
			}
		}
	}
	return false;
}
int main()
{
	Graph g(5); // Total 5 vertices in graph
	g.add(1, 0);
	g.add(2, 1);
	g.add(3, 4);
	g.add(4, 0);
	g.add(0,5);

	if(g.isRoute(1,1))
		cout << "there s a route" << endl;
	else
		cout << " no route exists" << endl;

	return 0;
}
