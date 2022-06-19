#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("snow.txt","r",stdin);
	int cases;//Ingresando la cantidad de casos
	cin>>cases;

	for (int i = 0; i < cases; ++i)
	{

		int n;//Cantidad de copos de nieve por bolsa
		cin>>n; 

		int mayor=0,cont=0,p=0;
		map<int,int>bag;//inicializacion del guardado de los distintos copos (copo,repeticiones)

		for (int j = 1; j <= n; ++j)
		{
			int aux;
			cin>>aux;
			int val = bag[aux];

			if(val != 0){//si se ha repetido el copo 
				if(p<val)p=val;
				cont = j-p-1;//retrocede a la posicion posterior al primer numero repetido 
				bag[aux] = j;//se guarda la posicion para seguir contando
			}
			
			bag[aux] = j;//se guarda la posicion para seguir contando
			++cont;//aumenta el contador de la bolsa
			
			if(mayor<cont)mayor = cont;//se diferencia la mayor bolsa
		}

		cout<<mayor<<endl;//impresion
	}
	return 0;
}

/*
Ejercicio No.3
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/
