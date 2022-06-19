#include <bits/stdc++.h>

using namespace std;

typedef stack<string> ss;//pilas de cartas que se acumulan al jugar
typedef vector<ss> vss;//vector de stack de strings que almacena las pilas de cartas que se forman al jugar

inline bool isValidCard(string c1, string c2)
{
	return c1[0] == c2[0] or c1[1] == c2[1];//se comparan dos cartas, para ver si la pinta y/o el numero coincide
}

int main(void)
{
	string current;//String auxiliar para la carta actual
	while (cin >> current and current != "#")//si current es distinto a # singifica que empieza una nueva baraja
	{
		vss piles(1);//inicializacion de la primera pila de cartas
		piles[0].push(current);//se agrega al vector la primera pila de cartas

		for (int i = 1; i < 52; ++i)
		{
			cin >> current;//se escanean las 51 cartas restantes de la baraja
			
			ss p;//la carta escaneada se transforma en una pila de una carta
			p.push(current);
			piles.push_back(p);
			bool change = false;
			
			do
			{
				change = false;
				
				for (int j = 1; j < piles.size(); ++j)//se compara la (carta de arriba de la) pila en la posicion j con todas las anteriores en el vector
				{
					current = piles[j].top();//auxiliar que guarda la baraja a analizar, la ultima pila creada
					int currentIndex = j - 1;//el indice se reduce en 1 para comparar la baraja en 1 espacio menos con la actual
					
					if (j > 2 and isValidCard(current, piles[j - 3].top()))//si la pila correspondiente a 3 espacios atrases valida
						currentIndex -= 2;//el indice se reduce en 2 para comparar la baraja en 3 espacios menos con la actual

					string card = piles[currentIndex].top();//auxiliar para ver la ultima carta en la baraja a comparar con la actual
					if (isValidCard(card, current))//se comparan las cartas de arriba de las barajas y se determina si son apilables
					{
						piles[currentIndex].push(current);//se apilan las barajas, la actual sobre la que se esta analizando con el indice
						piles[j].pop();//se quita del vector la baraja actual

						if (piles[j].empty())//si la posicion del vector que esta en la pila quitada esta vacia
							piles.erase(piles.begin() + j);//se elimina la posicion

						change = true;//condicion,efectua la busqueda mientras se siga apilando.
						break;
					}
				}

			} while(change);
		}

		cout << piles.size() << " pile" << (piles.size() == 1?" ":"s ") <<"remaining: ";//impresion de las pilas restantes
		//si solo hay una pila, se imprime sin la s
		for (int i = 0; i < piles.size(); ++i)
		{
			cout << piles[i].size();
			
			if (i + 1 != piles.size())//impresion del tamano de las pilas
				cout << " ";
		} 

		cout << "\n";
	}

	return 0;
}

/*
Ejercicio No.2
Tarea No.2
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/isanchez-aguilar/UVa-Solutions/blob/master/127%20-%20%22Accordian%22%20Patience.cpp
*/