#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,f;
	cin>>n;
	for (int l = 0; l < n; ++l)//por cada definicion de olas 
	{
		cin>>a>>f;
		//cout<<"\n";
		for (int k = 0; k < f; ++k)//por cada repeticion f
		{
			for (int i = 1; i <= a; ++i)//por la altura maxima a
			{
				for (int j = 0; j < i; ++j)//se imprime el numero de altura maxima en fila incrementalmente hasta llegar al mayor numero a
				{
				cout<<i;
				}
				cout<<"\n";
			}
			for (int i = a-1; i >= 1; --i)//se imprime el numero de altura maxima decrecientemente hasta llegar al valor 1
			{
				for (int j = i; j > 0; --j)
				{
					printf("%d",i );
				}
				cout<<"\n";
			}
			if(k!=f-1)cout<<"\n";//cambios de fila convenientes
		}
		if(l!=n-1)cout<<"\n";
	}

	
	return 0;
}

/*
Ejercicio No.4
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/