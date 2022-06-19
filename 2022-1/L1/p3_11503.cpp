#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

map<string,int> fl;//map que asigna una posicion (o nodo del arbol) a cada nombre
vector<int> friendship;//vector que almacena la cantidad de personas en un circulo

class UnionFind{ //Implementacion de Union find dada en clases
private: vector<int> p,rank;//Vectores de parents y de alturas
public:
	UnionFind(int N){//Constructor 
		friendship.assign(N,1);
		rank.assign(N,0);
		p.assign(N,0);//asigna todos los valores en 0
		for (int i = 0; i < N; i++){
			p[i] = i;
		} 
	}
	
	int findSet(int i){ 
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if(!isSameSet(i,j)){//verificar si los datos estan en el mismo conjunto
			int x = findSet(i), y = findSet(j);
			if(x==y)return;
			if(rank[x] > rank[y]){
				p[y] = x;//vemos cual raiz es mayor 
				friendship[x] += friendship[y];//cada vez que se asigne una raiz, se suma a al circulo las cantidades de los sub arboles sumados
				friendship[y] = 0;//se pone la cantidad de personas del arbol con menor raiz en cero 
			} 
			else{//se asignan los padres
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
				friendship[y] += friendship[x];
				friendship[x] = 0;
			}

		}
	}

	void printParent(){
		for (int i = 0; i < p.size(); ++i)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
		for (int i = 0; i < rank.size(); ++i)
		{
			printf("%d ", rank[i]);
		}
		printf("\n");
		for (int i = 0; i < friendship.size(); ++i)
		{
			printf("%d ", friendship[i]);
		}
		printf("\n");
	}


	int count(int n){
		return friendship[findSet(n)];//se cuenta la cantidad de personas en el circulo de la raiz del arbol
	}//si se buscara la del nodo en especifico seria 0 debido a la asignacion, por  lo que se busca el de la raiz
};


int main(int argc, char const *argv[])
{
	//freopen("p3.txt","r",stdin);

	int n;//escaneo de numero de tests
	cin>>n;

	while(n--){
		fl.clear();//se limpian las estructuras de almacenamiento globales
		friendship.clear();

		int N;
		cin>>N;//escaneo de numero de relaciones
		string name1,name2;

		int cont = 1;
		UnionFind uf(2*N);//espacio maximo es 2*N

		for (int i = 0; i < N; ++i)
		{
			cin>>name1>>name2;//escaneo de nombres
			//asignacion numeros para los nodos
			if(fl[name1] == 0){//se verifica si el nodo con el nombre ya existe
				fl[name1] = cont;
				cont++;
			}

			if(fl[name2] == 0){
				fl[name2] = cont;
				cont++;
			}
			uf.unionSet(fl[name1],fl[name2]);//se unen los valores asignados a los nombres
			printf("%d\n", uf.count(fl[name1]));//se imprime la cantidad de personas presentes en el circulo social actualmente

		}
		

	}
	return 0;
}

/*
Tarea No.2
Ejercicio No.3
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/
