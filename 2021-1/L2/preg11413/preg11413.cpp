#include <iostream>
#include <math.h>
#include <cassert>

using namespace std;

bool P(int mid, int m, int n,int *c){//funcion que valida si el valor es valido como contenedor
	
	int vessel = 1;
	int cap = mid;

	for (int i = 0; i < n; ++i)
	{	
		if(c[i]> mid )return false;//si un valor es mas grande que el contenedor entonces no es valido
		if(c[i]>cap){//si un valor es mas grande que la capacidad de un solo contenedor, entonces se comienza un nuevo contenedor
			if(vessel >= m )return false;//si se alcanca el maximo de contenedores, entonces no es valido
			cap = mid;//reinicio de capacidad del contenedor
			vessel++;//nuevo contenedor
		}
		cap -= c[i];//se le resta la leche puesta al nuevo contenedor de la capacidad de este
		
	}
	return true;
	 
}

int minMax(int m,int n, int *c){//funcion que busca las posibles capacidades de forma binaria
	int left = 0, right = 1e9;//valores maximos para c entre 1 y 1000000000

	while(left < right -1){

		int mid = (left + right)/2;//valor auxiliar para reducir el intervalo dee busqueda

		if(P(mid,m,n,c)){//si se encuentran valores validos hacia la derecha del arrglo
			right = mid;
		}
		else left = mid;//de lo contrario los valores deben estar en la izquierda
	}

	return right;//devuelve la posicion del dato mas a la derecha (el maximo valor del contenedor)
}

int main(int argc, char const *argv[])
{
	freopen("containers.txt","r",stdin);

	int n;

	while (scanf("%d",&n) != EOF){//condicion de termino
		
		int m;
		int vessels[n];

		cin>>m;//escaneo de datos

		for (int i = 0; i < n; ++i)//escaneo de datos
		{
			cin>>vessels[i];
		}

		int maxCap = minMax(m,n,vessels);//impresion

		printf("%d\n",maxCap);
		
		
	}
	return 0;
	
}

/*
Ejercicio No.2
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/
