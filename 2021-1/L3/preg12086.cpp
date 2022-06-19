/*
Secuencia de resistencias
nos dan las resistencias y el valor que poseen
2 consultas
	cambiar el valor de las resistencias
	cambiar el valor total de un rango de resistencias
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct FenwickTree{//Implementacion estandar de FenwickTree (rescatada de clase practica)
	vector<int> ft;
	FenwickTree();
	FenwickTree(int n){//constructor el vector interno donde guardar la suma
		ft.assign(n+1,0);
	}
	int query(int b){//obtener la suma hasta cierto rango
		int sum = 0;
		for (; b; b -=b&(-b)) sum += ft[b];
		return sum;
	}

	int query(int a, int b){//obtiene la suma por rank, RSQ
		return query(b) - (a == 1? 0 : query(a-1));
	}

	void update(int k, int v){//funcion de actualizacion desde k+LSOne(k) de las frecuencias acumuladas
		for (; k < (int)ft.size(); k+=k&(-k)) ft[k] += v;
	}
};

int main(int argc, char const *argv[])
{
	//freopen("potmeters.txt","r",stdin);
	int cases = 3;//cantidad maxima de casos

	for (int i = 0; i < cases; ++i)
	{
		int N;
		cin>>N;//cantidad de potmeters
		
		if(N==0)break;
		if(i)printf("\n");//blank entre casos

		vector<int> pot;//almacenamiento de los potentiometers
		FenwickTree ft(N);//creacion del fenwicktree

		for (int j = 0; j < N; ++j)
		{
			int aux;cin>>aux;//escaneo de resistencias iniciales
			pot.push_back(aux);
			ft.update(j+1,aux);//ajuste del j+1 dato por aux, se concidera j+1 por las posiciones iniciales desde 0 en el vector
		}

		string s;//posibles valores: END,S o M
		int a,b;
		cin>>s;
		printf("Case %d:\n",i+1);
		while(s[0]!='E'){
			cin>>a>>b;
			if(s[0]=='S'){//setea el potentiometer de la posicion a, la diferencia entre b y a
				ft.update(a,b-pot[a-1]);
				pot[a-1] = b;//luego se actualiza en el vector de almacenamiento
			}
			else printf("%d\n", ft.query(a,b));//caso M mide la resistencia entre los pot a y b
			cin>>s;
		}
		
	}
	return 0;
}

/*
Ejercicio No.6
Tarea No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/
