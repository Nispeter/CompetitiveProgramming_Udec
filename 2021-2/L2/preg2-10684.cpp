#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	freopen("p2in.txt", "r",stdin);

	while(cin>>N){

		if(N==0)break;//escaneo e inicializacion de variables
		int bet[N];

		for (int i = 0; i < N; ++i)
			cin>>bet[i];

		int max = -1, cont = 0,i = 0;
		while(N--){
			cont += bet[i];//suma de la secuencia mas grande	
			if(cont < 0)
				cont = 0;	
			if(cont > max)//en caso que la suma no sea viable
				max = cont;
			
			i++;
		}
		if(max > 0){
			printf("The maximum winning streak is %d.\n",max);
			continue;
		}
		printf("Losing streak.\n");
	}
	return 0;
}

/*
Ejercicio No.2
Tarea No.3
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:Solucion propia.
*/

