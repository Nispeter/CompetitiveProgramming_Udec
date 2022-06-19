#include <cstdio>
#include <vector>
using namespace std;

int x[100005];//donde se almacena la seucencia original

int LSOne(int n) {//analogo a b -=b&(-b)
	return n & (-n);
}

class FT {
private:
	vector<int> ft;

public:
	FT(int n) {
		ft.assign(n + 1, 0);//constructor el vector interno donde guardar la suma
	}
	int rsq(int b) {//obtener la suma hasta cierto rango
		int sum = 0;
		for (; b; b -= LSOne(b))
			sum += ft[b];
		return sum;
	}
	int rsq(int a, int b) {//obtiene la suma por rank, RSQ
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	void adjust(int k, int v) {//funcion de actualizacion desde k+LSOne(k) de las frecuencias acumuladas
		for (; k < (int) ft.size(); k += LSOne(k)) {
			ft[k] += v;
		}
	}
};

int main() {
	int n, k, d1, d2;//n: elementos en secuencia, k: rondas, d1: elemento 1 de operacion, d2: elemento 2 de operacion
	char q;//q: caracter auxiliar para escanear

	while (scanf("%d %d", &n, &k) != EOF) {
		FT ftNeg(n), ftZero(n);//Inicializacion de fenwick tree de valores cero y valores negativos

		for (int i = 1; i <= n; i++) {//escaneo de valores de la secuencia
			scanf("%d", &x[i]);
			if (x[i] < 0)//si se escanea un valor negativo entonces se agrega un 1 al ft de valores negativos 
				ftNeg.adjust(i, 1);
			if (x[i] == 0)//si se escanea un valor 0 entonces se agrega un 1 al ft de valores negativos 
				ftZero.adjust(i, 1);
		}

		for (int i = 0; i < k; i++) {
			scanf("%c", &q);//escaneo de operaciones
			while (q != 'P' && q != 'C')
				scanf("%c", &q);
			scanf("%d %d", &d1, &d2);

			if (q == 'P') {//caso de product between range 
				if (ftZero.rsq(d1, d2)) {//si hay algun cero en el rango del ft de ceros, entonces la multiplicacion siempre sera cero
					printf("0");
				} else if (ftNeg.rsq(d1, d2) % 2 == 0) {//en caso que el numero de negativos en rango sea par, etnonces la multiplicacion es positiva
					printf("+");
				} else {//cualquier otro caso es negativo
					printf("-");
				}
			} else if (q == 'C') {//caso de change position for value 
				//chequeo si los valores estan en ft distintos
				if (x[d1] >= 0 && d2 < 0)//si el valor a cambiar es positivo y el a insertar negativo
					ftNeg.adjust(d1, 1);//se ajusta el ft negativo
				else if (x[d1] < 0 && d2 >= 0)//si el valor a cmabiar es negativo y el a insertar es positivo o cero
					ftNeg.adjust(d1, 1);//se ajusta el ft negativo

				if (x[d1] != 0 && d2 == 0)//si el valor a cambiar es distinto de cero y el a insertar es cero
					ftZero.adjust(d1, 1);//se ajusta el ft cero
				else if (x[d1] == 0 && d2 != 0)//si el valor a cambiar es cero y el a insertar es distinto de cero
					ftZero.adjust(d1, -1);//se ajusta el ft cero

				x[d1] = d2;//reasignacion en el array de almacenamiento
			}
		}

		printf("\n");
	}

	return 0;
}


/*
Ejercicio No.7
Tarea No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2012532%20-%20Interval%20Product/src/UVa%2012532%20-%20Interval%20Product.cpp
*/