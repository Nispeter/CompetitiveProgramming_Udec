#include <stdio.h>
#include <string.h>

#define MAX 205

int N, M, D, Q;
int set[MAX], memo[MAX][MAX][15];

int dp(int i, int sum, int c)//dato actual, suma actual%D, dato actual incluido
{
	if(c == M && sum == 0)//si la suma es cero (osea divisible) y se han buscado todos los valores posibles
		return 1;
	if(c == M && sum != 0)//si la suma es cero y se han buscado todos M numeros entonces la cantidad es 0
		return 0;
	if(i == N) //si la cantidad de datos evaluada sobrepasa la cantidad N entoces se retorna 
		return 0;
	if(memo[i][sum][c] != -1)//si ya tiene un valor acumulado se retorna
		return memo[i][sum][c];

	memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+set[i])%D, c+1);//acumula la suma de las posibles combinaciones, eligiendo el numero o no

	return memo[i][sum][c];//se retorna la mayor cantidad de combinaciones divisibles por D apartir de la suma sum evaluando el dato c de i
}

int main()
{
	int i, j, res;

	j = 1;
	while(1)
	{
		scanf("%d %d", &N, &Q);//cantidad de datos, cantidad de queries
		
		if(N == 0 && Q == 0)
			break;

		for(i = 0; i < N; i++){
			scanf("%d", &set[i]);//scaneo de datos
		}
		printf("SET %d:\n", j);
		for(i = 0; i < Q; i++){
			scanf("%d %d", &D, &M);//divisor y cantidad de datos a elegir para la suma
			memset(memo, -1, sizeof(memo));
			res = dp(0, 0, 0);
			printf("QUERY %d: %d\n", i+1, res);
		}
		j++;
	}	
	return 0;
}

/*
Ejercicio No.3
Tarea No.4
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:https:https://github.com/Rasec09/UVa-Solutions/blob/master/10616%20-%20Divisible%20Group%20Sums.c
*/