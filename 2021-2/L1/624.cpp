#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> validD,valid,cd;
int N,t;

int dfs(int cont,int sum, int sumMax)
{
    if(cont==t)//si la cantidad de numeros analizados es igual a la cantidad de canciones 
    {
        if(cont==t and sum > sumMax and sum <= N)//si la suma es menor al maximo y es la mayor cantidad analizada hasta el momento, se almacena como posible solucion
        {
            sumMax=sum;
            validD=valid;//se reemplaza la secuencia global por la actual 
        }
        return sumMax;
    }

    valid.push_back(cd[cont]);
    sumMax = dfs(cont+1,sum+cd[cont],sumMax);//se busca la  iteracion sumando el actual valor de la secuencia 
    valid.pop_back();
    sumMax = dfs(cont+1,sum,sumMax); //se busca la iteracion sin sumar el actual valor de la secuencia 
    return sumMax;//se retorna el valor maxmimo de la suma 
}

int main(int argc, char const *argv[])
{
	//freopen("624in.txt","r",stdin);

	N = 0;//cantidad maxima de capacidad
	t = 0;//cantidad de canciones 

	while(scanf("%d%d",&N,&t) != EOF){
		int sumMax = 0;
		valid.clear();
		validD.clear();
		cd.clear(); 
		for (int i = 0; i < t; ++i){
			int aux;
			cin>>aux;
			cd.push_back(aux);//vector que almacena las canciones a copiar 
		}
		sumMax = dfs(0,0,sumMax);  //busqueda de la combinacion que mas canciones deje almacenar en la capacidad maxima
		for (int i = 0; i < validD.size(); ++i)
			printf("%d ", validD[i]);	
		printf("sum:%d\n", sumMax);			
	}

	return 0;
}
/*
Ejercicio No.7
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/