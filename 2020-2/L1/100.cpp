#include <iostream>
using namespace std; 
int may(int a, int b){//funcion que retorna el mayor valor
	if(a>b)return a;
	return b;
}
int men(int a, int b){//funcion que retorna el menor valor
	if(a<b)return a;
	return b;
}
int main()
{
	int a, b;
	while((scanf("%d %d",&a,&b)) == 2){
		int mayor = 0;
        int x = men(a,b);
        int y = may(a,b);
		for (int j = x; j <= y; ++j)//para encontrar la mayor cantidad de iteraciones een el intervalo
		{
			int aux = j, cont = 1;//variables auxiliares para identificar el valor actual de la division
			Loop: if (aux > 1)
			{
				if (aux%2 != 0)aux = 3*aux+1;//si el valor aux es impar
				else aux = aux/2;//si el valor es par
				++cont;//cantidad de iteraciones
				goto Loop;
			}
			if(cont >= mayor)mayor = cont;//se define la cuenta con mas iteraciones
		}

		cout << a <<" "<< b <<" "<< mayor <<"\n";
	}
	return 0;
}

/*
Ejercicio No.1
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/