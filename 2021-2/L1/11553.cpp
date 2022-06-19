#include <iostream>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	//freopen("11553in.txt","r",stdin);

	int t;
	cin>>t;

	while(t--){

		int n;//tamano del tablero de juego
		cin>>n;
		int M[n][n];//escaneo del grid

		int order[n];//orden de inspeccion de filas
		for (int i = 0; i < n; ++i){
			order[i] = i;
		}


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>M[i][j];//escaneo de valores de dulces
			}
		}

		int min = INT_MAX;//minimo a superar
		do{//por cada permutacion de filas 
			int tst = 0;

			for (int j = 0; j < n; ++j)
			{
			 	tst+= M[order[j]][j];//se suma el puntaje al contador de dulces del primer jugador 
			}
			
			if(tst < min) min = tst;//buscamos el maximo de dulces que le puede quitar el segundo jugador 

		}while(next_permutation(order,&order[n]));

		printf("%d\n", min);
	}

	return 0;
}
/*
El problema recae en ver las combinaciones de entrada y eleccion del primer jugador, debido a que el segundo
Siempre buscara la forma de hacer que el segundo tenga menos puntos
*/

/*
Ejercicio No.5
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/