// C++ program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
struct Graph
{
	int V, E;
	vector< pair<int, iPair> > edges;

	// Constructor
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}

	// Utility function to add an edge
	void addEdge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}

	// Function to find MST using Kruskal's
	// MST algorithm
	int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
	int *parent, *rnk;
	int n;

	// Constructor.
	DisjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u)
	{
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height
		a subtree of the other tree */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
	int mst_wt = 0; // Initialize result

	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());

	// Create disjoint sets
	DisjointSets ds(V);

	// Iterate through all sorted edges
	vector< pair<int, iPair> >::iterator it;
	for (it=edges.begin(); it!=edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v)
		{
			// Current edge will be in the MST
			// so print it
			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}


int main()
{
	freopen("p1in.txt","r",stdin);

	int n,cont = 0;
	while (scanf("%d",&n) != EOF){

		if (cont != 0)printf("\n");

		cont++;
		int v = n;
		int a, b, c;
		int base = 0;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>a>>b>>c;
			base += c;
		}
		printf("%d\n", base);

		int e = 0;
		vector<vector<int>> val;

		cin>>n;
		e+= n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a>>b>>c;
			vector<int>aux;
			aux.push_back(a);
			aux.push_back(b);
			aux.push_back(c);
			val.push_back(aux);
		}

		cin>>n;
		e+= n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a>>b>>c;
			vector<int>aux;
			aux.push_back(a);
			aux.push_back(b);
			aux.push_back(c);
			val.push_back(aux);
		}

		Graph g(v, e);
		for (int i = 0; i < e; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				g.addEdge(val[i][0], val[i][1], val[i][2]);
			}
		}

		//printf("%d %d\n", v ,e);
		int mst_wt = g.kruskalMST();

		cout << mst_wt << endl ;

	}

	return 0;
}


/*
Ejercicio No.1
Tarea No.4
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: solucion propia
Algoritmo de kruskal: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
*/