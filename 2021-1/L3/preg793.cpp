/*
Implementacion directa de union find
Se mantiene la supervision de una red de computadoras  donde los computadores pueden estar conectados entre si de manera bidireccional atravez de un enlace o atravez de otras computadoras.

Como saber si dos computadores estan en la misma red
Entregar respuestas afirmativas y negativas

Ir uniendo a medida que se reciven los datos

c es computadores que se van a conectar
q es la consulta de computadores que pertenecen a la misma red
*/
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class UnionFind{ //Implementacion de Union find dada en clases
private: vector<int> p,rank;//Vectores de parents y de alturas
public:
	UnionFind(int N){//Constructor 
		rank.assign(N,0);
		p.assign(N,0);//asigna todos los valores en 0
		for (int i = 0; i < N; i++){//se asigna como propio padre de nodo si mismo
			p[i] = i;
			rank[i] = 0;	
		} 
	}
	
	int findSet(int i){ 
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));// se encuentra de forma recursiva la raiz del set
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);//se muestra si los sets son iguales (raices similares)
	}

	void unionSet(int i, int j){
		if(!isSameSet(i,j)){//verificar si los datos estan en el mismo conjunto
			int x = findSet(i), y = findSet(j);
			if(x == y)return;
			if(rank[x] > rank[y]) p[y] = x;//vemos cual raiz es mayor
			else{//se asignan los padres
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};




int main(int argc, char const *argv[])
{
	//freopen("network.txt","r",stdin);
	int n,N;

	cin>>n;//escano de datos

	while(n--){
		char c;
		int success = 0,unsuccess = 0;
		int a,b;//par de computadores a conectar
		scanf("\n%d\n",&N);//escaneo de la catnidad de computadores (mas detalles de entrada)

		UnionFind uf(N);//creacion del objeto union find
		string str;//string auxiliar
		while(getline(cin,str) && str!=""){//escaneo de linea de entrada

			stringstream s(str);//stringstream para escanear desde el string str
			s>>c>>a>>b;//escaneo de los nodos a conectar
			if(str[0] == '\n')break;// caso de termino
			if(c == 'c'){//caso de que sea una nueva coneccion
				uf.unionSet(a,b);//se asigna la union en el arbol
			}
			else{
				if(uf.findSet(a) == uf.findSet(b)) success++;//si es una pregunta entonces se detecta si estan en el mismo conjunto
				else unsuccess++;
			}
		}

		printf("%d,%d\n",success,unsuccess );//impresion de datos 
		if(n!= 0)printf("\n");
	}
	return 0;
}

/*
Ejercicio No.2
Tarea No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/

