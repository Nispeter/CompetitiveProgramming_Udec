// C++ program for finding minimum cut using Ford-Fulkerson
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

#define V 50

int bfs(int rGraph[V][V], int s, int t, int parent[])
{

	bool visited[V];
	memset(visited, 0, sizeof(visited));


	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v=0; v<V; v++)
		{
			if (visited[v]==false && rGraph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[t] == true);
}

void dfs(int rGraph[V][V], int s, bool visited[])
{
	visited[s] = true;
	for (int i = 0; i < V; i++)
	if (rGraph[s][i] && !visited[i])
		dfs(rGraph, i, visited);
}

void minCut(int graph[V][V], int s, int t)
{
	int u, v;

	int rGraph[V][V]; // rGraph[i][j] indicates residual capacity of edge i-j
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; // This array is filled by BFS and to store path

	while (bfs(rGraph, s, t, parent))
	{
		int path_flow = INT_MAX;
		for (v=t; v!=s; v=parent[v])
		{
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for (v=t; v != s; v=parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
	}

	bool visited[V];
	memset(visited, false, sizeof(visited));
	dfs(rGraph, s, visited);

	for (int i = 0; i < V; i++)
	for (int j = 0; j < V; j++)
		if (visited[i] && !visited[j] && graph[i][j])
			cout << i+1 << " " << 1+j << endl;

	return;
}

int main()
{
	//freopen("p4in.txt","r",stdin);
	int n,m;
	while(cin>>n>>m){
		if(!n || !m)
			break;
		//V = n;
		int graph[V][V];
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				graph[i][j] = 0;
			}
		}
		int a,b,c;
		while(m--){
			cin>>a>>b>>c;
			graph[a-1][b-1] = c;
			graph[b-1][a-1] = c;

		}
		minCut(graph,0,1);
		printf("\n");
	}
	/*int graph[V][V] = { {0, 0, 70, 30, 0}, 	
						{0, 0, 0, 50, 0},
						{0, 25, 0, 0, 0},
						{0, 0, 5, 0, 15},
						{0, 10, 20, 0, 0},
					};

	minCut(graph, 0, 1);*/
	/*int graph[V][V] = { {0, 0, 0, 0, 0},
						{0, 0, 25, 0, 10},
						{70, 0, 0, 5, 20},
						{30, 50, 0, 0, 0},
						{0, 0, 0, 15, 0},
					};

	minCut(graph, 0, 1);*/

	return 0;
}

/*
Ejercicio No.4
Tarea No.4
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:Solucion propia.
min-cut algorithm: https://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/
*/