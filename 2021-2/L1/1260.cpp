#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T; //cantidad de test cases

	while(T--){

		int n;
		cin>>n;

		int cont = 0;
		vector<int> sales;//almacenamiento de ventas

		for (int i = 0; i < n; ++i)//por cada venta analizar las anteriores
		{
			int aux;
			cin>>aux;
			sales.push_back(aux);

			for (int i = sales.size() - 2; i >= 0; --i)
			{
				if(aux >= sales[i])cont++;//si es menor o igual se suma 1 la contador
			}
		}

		printf("%d\n", cont);//imprime la suma de las n-1 ints que cumplan la diferencia en orden
	}

	return 0;
}

/*
Ejercicio No.1
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/