#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> valid,cd;//combinaciones validas, cds a sumar 
vector<bool> comb;
int N,t,quan;

void dfs(int cont,int sum)
{
	if(cont == t)return;//si se llega al ultimo dato a evaluar 
    if(sum == N){//si la suma es valida
    	for (int i = 0; i < valid.size(); ++i)
    	{
    		quan++;//se aumenta la cantidad
    		if(i == valid.size()-1)printf("%d",valid[i]);
    		else printf("%d+",valid[i]);
    	}
    	printf("\n");
    	//return;
    }
    valid.push_back(cd[cont]);
    dfs(cont+1,sum+cd[cont]);//busqueda en profundidad incluyendo el numero evaluado
    valid.pop_back();
    dfs(cont+1,sum);//busqueda en profundidad sin incluir el numero evaluado
}

int main(int argc, char const *argv[])
{
	//freopen("574in.txt","r",stdin);
	N = 0;//valor buscado
	t = 0;//cantidad de numeros a entregar

	while(cin>>N>>t){
		if(N == 0 or t == 0)break;
		quan = 0;
		int sumMax = 0;

		comb.clear();
		fill(comb.begin(),comb.end(),true);

		valid.clear();
		cd.clear(); 
		for (int i = 0; i < t; ++i){
			int aux;
			cin>>aux;
			cd.push_back(aux);//escaneo de valores 
		}
		dfs(0,0); //busqueda en profundidad de las combinaciones de numeros hasta llegar  al valor deseado  
		if(quan == 0)//si la cantidad de soluciones es cero
	    	printf("NONE\n");

	}

	return 0;
}

/*
Ejercicio No.8
Tarea No.1
UVA id: Nisp
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/