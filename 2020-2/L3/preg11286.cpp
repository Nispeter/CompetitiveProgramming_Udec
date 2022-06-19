#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cstdio>

using namespace std;

int selec = 5;//ramos a evaluar


int main(int argc, char const *argv[])
{
	//freopen("sample.txt","r",stdin);
	
	int n;//cantidad de casos

	while(cin>>n && n!= 0){

		vector<pair<int, vector<int>>> prefs;//almacenamiento de las preferencias de los alumnos

		for (int l = 0; l < n; ++l)
		{

			vector <int> aux;//almacenamiento de los 5 ramos de cada alumno
			for (int i = 0; i < selec; ++i){
				int num;
				cin>>num;
				aux.push_back(num);
			}
			int secFound= -1;//auxiliar para encontrar una combinacion existente de ramos
			sort(aux.begin(),aux.end());//reordenan los ramos para poder comparar de forma mas facil
			
			for (int i = 0; i < prefs.size(); ++i)//comparacion entre los ramos amacenados y los ingresados
			{
				if(prefs[i].second== aux)secFound=i;
			}

			if(secFound != -1){//si se encuentra la misma combinacion de ramos entonces se agrega uno a la cantidad de repeticiones
				prefs[secFound].first++;
			}
			else{//de lo contrario se almacena en el vector prefs
				pair<int,vector<int>>auxB;
				auxB.first = 1;auxB.second = aux;
				prefs.push_back(auxB);
			}
		}
		int max = 0;
		int maxAux = 0;
		for (int l = 0; l < prefs.size(); ++l)
		{
			if(prefs[l].first>max){//impresion del numero de alumnos que asisten a la combinacion mas popular
				max = prefs[l].first;
				maxAux = 0;
			}
			if(prefs[l].first==max)maxAux += prefs[l].first;//caso de que no sea unica la combinacion de ramos
		}
		cout<<maxAux<<endl;
	}

	return 0;
}

/*
Ejercicio No.2
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/