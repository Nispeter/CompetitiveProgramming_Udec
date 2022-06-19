#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
vector<int>rep;//almacenamiento de repeticiones de datos



class UF {
  int *id, cnt, *sz;
  public:
// Create an empty union find data structure with N isolated sets.
UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
~UF() { delete[] id; delete[] sz; }

// Return the id of component corresponding to object p.
int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
}
// Replace sets containing x and y with their union.
void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    // make smaller root point to larger one
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
}
// Are objects x and y in the same set?
bool connected(int x, int y) { return find(x) == find(y); }
// Return the number of disjoint sets.
void print(int N){
	for (int i = 0; i < N; ++i)
	{
		printf("%d ",find(id[i]) );
	}
	printf("\n");
}
int count(int N){

	rep.assign(N,0);//todas las repeticiones equivalen a cero

	for (int i = 0; i < N; ++i)
	{
		rep[find(id[i])]++;//se encuentra la raiz del conjunto y se suma a la posicion del dato en rep
	}

	int max = 1;
	for (int i = 0; i < rep.size(); ++i)
	{	
		if(rep[i] >= max)max = rep[i];//se encuentra la posicion mas repetida
	}
	return max;
	}
};




int main(int argc, char const *argv[])
{

	//freopen("friends.txt","r",stdin);
	
	int n;
	cin>>n;
	while(n--){

		int N,M;
		cin>>N>>M;//escaneo de datos
		UF uf(N);

		for (int i = 0; i < M; ++i)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;//al usar a y b como posiciones debemos restar 1 para que sea acorde
			uf.merge(a,b);//creacion de la union de pares
		}
		printf("%d\n", uf.count(N));//se cuenta el conjunto con mas datos
		rep.clear();
	}
	return 0;
}


/*
Ejercicio No.4
Tarea No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
Union find rescatado de: https://stackoverflow.com/questions/8300125/union-find-data-structure/8303593
*/
