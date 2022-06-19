#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("test.txt","r",stdin);
	int t;
	cin>>t;

	for (int j = 0; j < t; ++j){

		int n,max = 1;
		cin>>n;
		int r[n+1],dif[n];
		r[0]=0;//caso base donde se cuenta el piso como altura

		for (int i = 1; i < n+1; ++i)
		{
			cin>>r[i];//Escaneo de rungs
			dif[i-1]=r[i] - r[i-1];//diferencias entre rungs
			if(dif[i-1]>max)max = dif[i-1];//maxima diferencia (fuerza minima)
			
		}

		if(max < dif[0])max = dif[0];
		int aux = max;//variable auxiliar para encontrar el minimo de fuerza

		for (int i = 0; i < n; ++i)
		{//se recorre toda la escalera
			if(dif[i] == max)max--;//si se encuentra una copia de la fuerza requerida en una escalera 
			else if(dif[i]>max){//si se repite mas de una vez una altura entonces el menor sera la maxima diferencia de alturas + 1
				aux++;
				break;
			}
		}

		printf("Case %d: %d\n",j+1,aux );
	}

	return 0;
}

/*
Ejercicio No.1
Tarea No.5
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/