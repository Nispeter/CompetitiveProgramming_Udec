#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("11565in.txt","r",stdin);

	int N;
	cin>>N;

	while(N--){

		int a,b,c;//variables que satisfacer con x ,y & z
		bool found = false;//auxiliar que almacena si se encuentra la solucion
		cin>>a>>b>>c;//escaneo de igualdades de formula
		//por los intervalos dados, las variables solo pueden tomar valores desde -100 a 100 (como maximo sin contar poda)
		for (int x = -100; x <= 100; ++x)
		{
			for (int y = -100; y <= 100; ++y)
			{
				for (int z = -100; z <= 100	; ++z)
				{
					if(x == y or y == z or z == x)continue;//si son iguales entonces no cuenta el loop
					if(x+y+z == a and x*y*z == b and x*x+y*y+z*z == c){//si se cumplen las condiciones de las formulas entonces se encuentra la solucion
						found = true;
						printf("%d %d %d\n",x,y,z);//imprecion de valores 
						break;
					}

				}
				if(found)break;
			}
			if(found)break;
		}
		if(!found)printf("No solution.\n");
	}
	return 0;
}

/*
Ejercicio No.4
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
Disclaimer: Naive implementation
*/