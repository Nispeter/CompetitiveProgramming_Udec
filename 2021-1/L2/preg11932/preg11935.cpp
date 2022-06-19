#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("desert.txt","r",stdin);

	while(true){

		double km,n;//contador de kilomtereos y consumo auxiliar
		int rendimiento = 100,kmAnterior = 0,leaks = 0;//contadores de consumo, leaks y el kilometro anterior
		double consumo = 0,mayorTanque = 0;//contador de consumo total  y de magnitud del mayor tanque
		string s,extra;

		cin>>km>>s>>extra>>n;

		if(n == 0)break;

		while(true){

			int d;
			string aux;//string que identifica la siguente operacion

			cin>>d>>aux;//escaneo de datos

			consumo+= (d - kmAnterior) *n/100; //calculo del tanque en base a distancia y consumo auxuliar
			kmAnterior = d;
			mayorTanque = max(mayorTanque,consumo);//comparacion para encontrar el mayor tanque 



			if(aux[0] == 'F'){//caso fuel station
				string extra;//string auxiliar de trash
				cin>>extra>>n; //se escanea el nuevo consumo auxiliar
				n+= 100*leaks; //recalculo del cosumo por leaks
			}
			else if(aux[0] == 'L'){//caso de un nuevo leak
				n-= 100*leaks; //se resta el consumo de por leaks anteriores
				leaks++;
				n+= 100*leaks; //se recalcula el consumo por leaks
			}
			else if(aux[0] == 'M'){//caso de un nuevo mecanico
				n-= 100*leaks;//se resta el consumo potencial por leaks
				leaks = 0; //se re definen los leaks como cero
			}
			else if(aux[0] == 'G' && aux[1] == 'a'){//caso de una estacion de servicio
				string extra;//string auxiliar de trash
				cin>>extra;
				consumo = 0;//se define el consumo total del tanque como cero
			}
			else if(aux[0] == 'G' && aux[1] == 'o' ){//caso de meta
				break;//se termina de evaluar 
			}
					
			//printf("%.3lf//%d\n",consumo,n);
		}

		printf("%.3lf\n",mayorTanque );
	}


	return 0;
}



/*
Ejercicio No.4
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/
