#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	char in[100001];
	while(scanf("%s",in)!=EOF){//condicion de finalizacion del escaneo
		string beiju="",word="";
		string aux = "";//strings auxiliares para formar el beiju
		bool escaneando = false;//auxiliar para indicar si se forma el beiju
		for (int i = 0; i < strlen(in); ++i)
		{
			if(in[i]=='['){//si se encuentra un corchete, se inicia el guardado de la palabra
				escaneando =  true;
			}
			else if(in[i]==']'){//si se encuentra, se finaliza el guardado y se pone en una variable
				escaneando = false;
				aux += beiju;//se establece el orden correcto de los strings
				beiju = aux;
			}
			else if(escaneando){//mientras se este escaneando la palabra, se guarda en un auxiliar
				aux+=in[i];
			}
			else word+=in[i];//si no aparecen los corchetes, se forma la oracion normalmente
		}
		cout<<beiju<<word<<endl;//imprecion del beiju y luego la palabra

	}
	return 0;
}

/*
Ejercicio No.7
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/