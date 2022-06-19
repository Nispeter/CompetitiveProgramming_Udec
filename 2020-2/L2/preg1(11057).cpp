#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;





int main(int argc, char const *argv[])
{
	
	ifstream File("input.txt");
	while(!File.eof()){//Escaneando el file
		vector<int>costos;//se crea un vector de costos .
		int cant,aux,plata;//contadores de dinero, de libros y de cantidad de libros
		File>>cant;
		cin>>cant;
		for (int i = 0; i < cant; ++i)//escaneo de datos 
		{
			File>>aux;
			cin>>aux;
			costos.push_back(aux);

		}
		File>>plata;
		sort(costos.begin(),costos.end());//se ordenan los datos en el vector
		int menor = 1000001;//dato menor auxiliar para identificar la menor cantidad posible de dinero.
		pair<int,int>menores;//par de soluciones
		int i = 0,j = cant-1;
		while(i<j){//se itera por ambos lados del vector por eficiencia 
			if( i!=j && costos[i]+costos[j]==plata && abs(costos[i]-costos[j])<menores ){
				menores.second = costos[i];menores.first = costos[j];
				menor = abs(costos[i]-costos[j]);
				--j;
				++i;
			}
			else if(costos[i]+costos[j]<plata)++i;//mientras no se encuentre una combinacion de suma de precios menor, se sigue iterando
			else --j;
		}
		cout<<"Peter should buy books whose prices are "<<menores.second<<" and "<<menores.first<<"."<<endl<<endl;//impresion de valores resultantes 

	}
	return 0;
}

/*
Ejercicio No.1
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/