#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;//cantidad de casos
	string s;

	cin>>n;//escaneo de datos

	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		//variables de los extremos de intervalo para el calculo del nodo del medio en el arbol
		long long int a = 0, c = 1;//nodo izquierdo
		long long int e = 1, f = 1;//nodo del medio
		long long int b = 1, d = 0;//nodo derecho

		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == 'L'){//si la operacion es a la izquierda del arbol
				b = e; d = f;//se recalcula el nodo derecho
				e = a + b;//se caclcula la fraccion del nuevo nodo del medio segun formula (a+b)/(b+d)
				f = c + d;
			}
			else if(s[i] == 'R'){//si la operacion es a la izquierda del arbol
				a = e; c = f;//se recalcula el nodo izquierdo
				e = a + b;//se caclcula la fraccion del nuevo nodo del medio segun formula (a+b)/(b+d)
				f = c + d;
			}
		}

		printf("%lli/%lli\n",e,f );//impresion de datos

	}
	return 0;
}

/*
Ejercicio No.1
Tarea No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/
