#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Program to find Dijkstra's shortest path using
// priority_queue in STL

# define INF 0x3f3f3f3f

// p ==> Integer Pair
typedef pair<int, int> p;

// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,
									int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}


// Prints shortest paths from src to all other vertices
void shortestPath(vector<pair<int,int> > adj[], int V, int src, int dest)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// http://geeksquiz.com/implement-min-heap-using-stl/
	priority_queue< p, vector <p> , greater<p> > pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// Get all adjacent of u.
		for (auto x : adj[u])
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = x.first;
			int weight = x.second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
    if(dist[dest] >= 1061109567)
        printf("unreachable\n");
	else 
        printf("%d\n",dist[dest]);
}



int main(int argc, char const *argv[])
{
    //freopen("p1.txt","r",stdin);
    //freopen("p1_out.txt","w",stdout);

    int N;
    cin>>N;
    
    for (int i = 0; i < N; i++)
    {
        int n,m,s,t;
        cin>>n>>m>>s>>t;

	    vector<p> adj[n];
        
        for (int j = 0; j < m; j++)
        {
            int x,y,val;
            cin>>x>>y>>val;
            addEdge(adj,x,y,val);
        }

        cout<<"Case #"<<i + 1<<": ";
        shortestPath(adj,n,s,t);
        
    }
    
    return 0;
}


/*
Tarea No.2
Ejercicio No.1
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
Algoritmo Dijkstra rescatado de: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
*/


