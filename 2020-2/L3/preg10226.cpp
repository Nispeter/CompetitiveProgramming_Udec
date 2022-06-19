#include <iostream>
#include <map>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    //freopen("trees.txt","r",stdin);
	int cases;
	cin>>cases;
    cin.ignore();//se ignoran los espacios correspondientes 
    cin.ignore();

	for (int i = 0; i < cases; ++i)
	{

		string tree;
		int cont = 0;
		map<string,int> m;//almacenamiento de raza y cantidad escaneada

		while(getline(cin,tree)){
			if(tree.size() == 0)break;//si se detecta un espacio vacio, para de iterar
			cont++;
			if(m[tree]==0){//si se encuentra el arbol, se inicializa el contador de esa especie de arboles;
				m[tree]=1;
			}
			else{//se incrementa el contador respectivo
				m[tree]++;
			}
		}

		map<string,int>::iterator it = m.begin();//inicializacion del iterador 

        
		for (pair<string,int> itr:m)//impresion de datos con for especial 
		{
			cout<<itr.first;
			printf(" %.4lf\n",(double)itr.second*100/cont );//impresion de especie y porcentaje de aparicion con 4 decimales
		}
        if(i!=cases-1)printf("\n");
	}
	return 0;
}

/*
Ejercicio No.1
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/