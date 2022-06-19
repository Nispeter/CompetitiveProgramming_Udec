#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;//escaneo de cantidad de operaciones
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int jobs,pos;
		cin>>jobs>>pos;//escaneo de cantidad de trabajos y de posiciones

		queue<pair<int,int>>que;//cola que almacena la prioridad y si es la impresion buscada 
		int max = 0;

		for (int j = 0; j < jobs; ++j)
		{	
			int a;int b;
			cin>>a;//escaneo de priodidad auxiliar
			if(a > max)max = a;
			if(j == pos)b=1;//asignacion de valor a buscar dependiendo de la posicion en la que esta en la cola
			else b=0;

			pair <int,int> aux = {a,b};
			que.push(aux);
		}
		
		int cont = 0;
		for (int j = max; j > 0; --j)//analizando desde la priodidad mayor
		{
			int num = que.size();
			for (int k = 0; k <num; ++k)
			{

				if(que.front().first == j){//si la prioridad es la que se busca en el for, se quita de la cola
					num +=num + 1;//se da un loop a la cola cuando se elimina un elemento para buscar mas de ese valor
					++cont;//aumento en cantidad
					if(que.front().second == 1){
						goto end;//si se quita el valor buscado, finalizar el loop
					}
					que.pop();//se quita el valor del queue
				}
				else{//si no se encuentra una prioridad correcta, se quita el valor de la cola y se pone al final
					que.push(que.front());
					que.pop();
				}
				
			}
		}
		end:
		printf("%d\n",cont);//impresion de la cantidad de impresiones antes de la deseada

	}
	return 0;
}
/*
Ejercicio No.8
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/