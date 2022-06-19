#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	long long int n;
	//normalmente se usa counting sort, pero el margen basta para un algoritmo de complejidad O(n*log n)
	while(true){

		cin>>n;//variables de almacenamiento
		vector<int> age;

		if(n==0)break;//caso de temrino

		for (int i = 0; i < n; ++i)//escaneo y almacenamiento de datos
		{	
			int aux;
			cin>>aux;
			age.push_back(aux);
		}

		sort(age.begin(),age.end());//uso de merge sort, el cual cuadra dentro del tiempo esperado

		for (int i = 0; i < n; ++i)//Impresion de datos equiespaciados
		{
			if(i != n -1)cout<<age[i]<<" ";
			else cout<<age[i];//no hay que espaciar el ultimo dato
		}
		printf("\n");
	}
	

	return 0;
}

/*
Ejercicio No.5
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/