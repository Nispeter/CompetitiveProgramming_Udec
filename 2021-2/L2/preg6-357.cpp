#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int coins[] = {1,5,10,25,50};

	//freopen("p6in.txt", "r", stdin);
	while (cin >> n){

	vector <long long> coin_count(30001,0);
	coin_count[0]= 1;
	for (int i = 0; i < 5; ++i)//calculo de todas las posiblilidades hasta 30000
	{
		for (int j = coins[i]; j < 30001; ++j)
		{
			coin_count[j] += coin_count[j - coins[i]];//suma se la cantidad posible de monedas actual + 
		}//la cantidad posible de antes de la moneda insetada a la nueva combinacion (explicacion mas abajo)
	}

/*
30:
									+1 (de 30 mondedas de 1, valor inicial)
5 | 25 | 20 | 15 | 10 | 5  | 0  	+6 (reduccion de 30 en 6 cantidades distintas de 5's)
--------------------------------
10| 20 | 10 | 0  | -  | -  | - 		+3 (reduccion de 30 en 3 cantidades distintas de 10's) +4(combinaciones posibles para 20 apartir de 5's)+2 (posibles para 10 apartir de 5's)
--------------------------------
25| 5  | 0  | -  | -  | -  | - 		+1 (reduccion de 30 en 1 cantidad de 25's) +1(combinaciones posibles para 5 apartir de 5's)

la cantidad de combinaciones distintas del numero anterior corresponde a la cantidad de de veces que se 
le puede restar a 30 el numero c[i] mas los valores que coincidan en i posteriores 
por lo que las combinaciones de una cantidad especifica se establecen en base a la cantidad del valor anterior
a insertar la moneda. Lo que se repite hasta poner todas las monedas 
*/
	
		if(coin_count[n] != 1)
			cout<<"There are "<<coin_count[n]<<" ways to produce "<<n<<" cents change."<<endl;
		else 
			printf("There is only 1 way to produce %d cents change.\n",n );
	}

	return 0;
}

/*
Ejercicio No.6
Tarea No.3
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:Solucion propia.
*/