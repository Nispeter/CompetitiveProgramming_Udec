#include <bits/stdc++.h>

using namespace std;

typedef long long li;

const int N = 2009;
const int INF = int(1e9) + 777;

struct edge{ //cada arista posee un vertice de origen y de destino, ademas del costo
	int to, f, c;
	edge () {}
	edge (int to, int f, int c) : to(to), f(f), c(c) {}
};

int n, m;
int s, t;
vector<edge> edges; //vector de vertices 
vector <int> g[N]; //grafo completo 
int u[N], cu;

void addEdge(int v, int to, int cap){ //se agregan nodos al grafo de flujo 

	g[v].push_back(edges.size());		
	edges.push_back(edge(to, 0, cap));

	g[to].push_back(edges.size());
	edges.push_back(edge(v, 0, 0));
}

int dfs(int v, int need){ //dfs atravez del arbol de nodos
	if(v == t) return need;
	u[v] = cu;
	for(auto to : g[v]){
		edge &e = edges[to];
		if(u[e.to] != cu && e.c - e.f >= need){
			int add = dfs(e.to, need);
			if(add > 0){		//si la diferecia es positiva se agrega a los vertices 
				edges[to].f += add;
				edges[to ^ 1].f -= add; //reajustes del valor en caso de repeticion de vertifces 
				return add;
			}
		}
	}
	return 0;
}

li enlarge(int k){//se agranda el subgrafo
	li res = 0;
	while(true){
		++cu;
		int add = dfs(s, k);
		res += add;
		if(add == 0) break; //termina cuando no se le puede agregar mas valor 
	}
	return res;
}

li maxFlow(){ //calculo del flujo maximo 
	li flow = 0;
	for(int k = (1 << 29); k > 0; k >>= 1){
		flow += enlarge(k);
	}
	return flow;
}

//Max-flow min-cut problem

int main() {
	//freopen("input.txt", "r", stdin);
	int nn, mm;
	cin >> nn >> mm; 	//cantidad de vetices y artistas
	n = nn + mm + 5;
	m = nn + mm + mm + mm + 5;
	s = n - 1, t = n - 2;
	
	for(int i = 0; i < nn; ++i){ 	//peso de los vertices 
		int a;
		cin >> a;
		addEdge(i + mm, t, a);
	}

	li sum = 0;
	for(int i = 0; i < mm; ++i){ //arista de los vertices u a v con peso w 
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		sum += w;				//cantidad de peso maximo sin contar los vertices 
		
		addEdge(s, i, w);
		addEdge(i, u + mm, INF);
		addEdge(i, v + mm, INF);
	}
	
	li fl = maxFlow(); 		//flujo maximo 
	cout << sum - fl << endl;
	
	return 0;
}

/*
Tarea No.5
Ejercicio No.1
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria: https://codeforces.com/blog/entry/63544
*/