#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> sv;//almacenmaiento de las distintas mutaciones
char nc[] = {'A','C','G','T'};
string str;//secuencia original
int k,n;//cantidad de aminoacidos y cantidad de estos que pueden mutar

void dfs(string s,int tam, int cont){
	if(cont > k){//si la cantidad de mutaciones es mayor a lo permitido se retorna
		return;
	}
	else if(tam == n){//si la longitud es igual a la permitida entonces es una mutacion valida y se almacena 
		sv.push_back(s);
		return;
	}
	//cout<<s<<endl;
	for (int i = 0; i < 4; ++i)//por cada base se puede agregar a la secuencia de forma recursiva
	{
		int aux = cont;
		if(str[tam] != nc[i]){
			aux+= 1;//si el caracter de la secuencia es distinta a la original, entonces se aumenta el contador de mutaciones
			dfs(s+nc[i],tam + 1,aux);
		}
		else dfs(s+str[tam],tam + 1,aux);//de lo contrario se agrega la base de la secuencia original sin modificar el contador de mutaciones
	}
}

int main(int argc, char const *argv[])
{
	//freopen("11961in.txt","r",stdin);
	int t;//casos 
	cin>>t;
	while(t--){
		sv.clear();n = 0;k = 0;
		cin>>n>>k;
		cin>>str;
		dfs("",0,0);//inicializacion de la busqueda de secuencia con dfs
		printf("%d\n", (int)sv.size());

		for (int i = 0; i < sv.size(); ++i)
		{
			cout<<sv[i]<<endl;
		}
	}

	return 0;
}

/*
Ejercicio No.10
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/