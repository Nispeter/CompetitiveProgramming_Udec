#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("query.txt","r",stdin);
	string reg;

	typedef pair<int,vector<int>>pa;//estructura que almacena la suma de los valores de iteracion, y un vector con el q_num y el periodo
	priority_queue<pa,vector<pa>,greater<>>q;//cola de prioridad ordenados segun el valor entero de pa mas grande

	while(cin>>reg){//escaneo de register
		if(reg[0]=='#')break;//escaneo hasta un #

		int q_num,p;
		cin>>q_num>>p;//escaneo de q_num y el periodo

		vector<int>aux{q_num,p};
		pair<int,vector<int>>auxP{p,aux};
		q.push(auxP);//almacenamiento de variables en el priority queue
	} 

	int n;
	cin>>n;//cantindad de calculos que se van a hacer

	queue<int>xar;//cola que almacena los q_num de los valores que ya han sido seleccionados dentro del priority queue
	for (int i = 0; i < n; ++i)
	{
		/*
		Loop que itera sobre el priority queue y que al primer valor de la cola, aumenta su numero que ordena el mismo pa en la cola
		en funcion a su periodo, luego se vuelve a insertar y ordenar el el priority queue.

		la gracia de usar un priority queue en esta situacion es que ordena automaticamente los pa segun su valor 
		acumulativo de entero, los cuales lo reposiciones luego de haber sido incrementado y por ende agregado
		al queue auxiliar
		*/

		auto current = q.top();
		q.pop();
		int valAux = current.second[1]+current.first;
		
		xar.push(current.second[0]);

		vector<int>aux{current.second[0],current.second[1]};
		pair<int,vector<int>>auxP{valAux,aux};
		q.push(auxP);
	}
	while(xar.size()>0){//impresion de los datos del queue auxliar en orden
		cout<<xar.front()<<endl;
		xar.pop();
	}
	return 0;
}

/*
Ejercicio No.6
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/