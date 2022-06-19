#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int cards;

	while(scanf("%d",&cards)){//escaneo de tamano de baraja
		queue<int>deck;//baraja de cartas representada por una cola
		if(cards == 0)return 0;
		for (int i = 0; i < cards; ++i)
		{
			deck.push(i+1); //se agregan cartas con sus posiciones relativas en la baraja

		}
		if(cards == 1){//si la baraja tiene solo una carta
			printf("Discarded cards:\n");
			printf("Remaining card: %d\n",deck.front() );
		}
		else {
			printf("Discarded cards: %d",deck.front());//se descarta la primera carta de la baraja
			deck.pop();//se elimina de la cola
			deck.push(deck.front());//se coloca la siguente carta al final de la cola
			deck.pop();//se elimina de la cola la isntancia original
			while (deck.size() > 2)//se repite el procedimiento anterior hasta que queden solo dos cartas en la baraja
			{
				printf(", %d",deck.front() );
				deck.pop();
				deck.push(deck.front());
				deck.pop();
				if(deck.size()==2)break;
			}
			printf(", %d\n",deck.front() );//se descarta la penultima carta
			deck.pop();
			printf("Remaining card: %d\n",deck.back() );//se muestra la carta restante
		}

	}
	return 0;
}

/*
Ejercicio No.9
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/

