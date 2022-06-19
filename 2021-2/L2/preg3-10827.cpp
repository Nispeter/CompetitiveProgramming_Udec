#include<cstdio>
#define SIZE 350
#include<algorithm>
using namespace std;
int grid[SIZE][SIZE];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int tc, n;
	scanf("%d", &tc);//test cases
	for(int i = 0; i < tc; ++i){
		scanf("%d", &n);//dimensiones del grid de tours
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){//escaneo de valores del tours
				scanf("%d", &grid[j][k]);
				grid[j + n][k] = grid[j][k + n] = grid[j + n][k + n] = grid[j][k];
			}//se usa un grid de 2n*2n para que se pueda atravezar el grid en los  bordes (poder dar vuelta el grid por los lados)
		}
		/*for(int j = 0; j < 2*n; ++j){
			for(int k = 0; k < 2*n; ++k){
				printf("%d ", grid[j][k]);
			}
			printf("\n");
		}
		printf("\n\n");*/

		for(int j = 0; j < 2*n; ++j){//se suma a cada bloque los valores de la suma anterior de los bloques adyacentes de arriba e izquierda 
			for(int k = 0; k < 2*n; ++k){ //es decir que se suma todo el tablero evitando repeticiones de numeros para despues ir restando en medida que se achica el rectangulo mas grande
				if(j > 0) grid[j][k] += grid[j-1][k] ;
				if(k > 0) grid[j][k] += grid[j][k - 1];
				if(j > 0 && k > 0) grid[j][k] -= grid[j - 1][k - 1];//se le resta sus diagonales superiores izquierdas
			}
		}
		
		/*for(int j = 0; j < 2*n; ++j){
			for(int k = 0; k < 2*n; ++k){
				printf("%d ", grid[j][k]);
			}
			printf("\n");
		}
		printf("\n\n");*/


		int maxRect = -3e7;//rectangulo mas grande del grid
		int subRect = maxRect;//auxiliar para almacenar el rectangulo maximo temporal de cada iteracion

		for(int j = 0; j < n; ++j) 
			for(int k = 0; k < n; ++k)//por cada numero del grid
				for(int l = j; l < n + j && l < 2*n; ++l) //se usa como ezquina superior izquierda de la suma de un rectangulo (por cada sub rectangulo)
					for(int m = k; m < n + k && m < 2*n; ++m){
						subRect = grid[l][m];//al rectangulo mas grande con posicion l,m 
						if(j > 0) subRect -= grid[j-1][m];//se le resta la suma anterior de los bloques de arriba e izquierda
						if(k > 0) subRect -= grid[l][k -1];
						if(j > 0 && k > 0) subRect += grid[j-1][k-1];//y se suma su diagonal superior izqierda (para evitar restas repetidas)
						maxRect = max(maxRect, subRect);//se verifica si el sub rectangulo es mayor
				}
		printf("%d\n", maxRect);

	}
	return 0;

}

/*
Ejercicio No.3
Tarea No.3
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:https://github.com/asanchez128/UVa-Solutions/blob/master/10827%20-%20Maximum%20sum%20on%20a%20torus.cpp
*/