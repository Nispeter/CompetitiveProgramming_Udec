#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int parse(char *l, int n[]) {
    int neg = 1, dec = 0, tmp = 0, pos = 0;//contadores de negativo,contador de inicio de numereo,valor auxiliar del numero convertido y posicion de numero en el arreglo c. 
    for(int i = 0; l[i]; i++) {
        if( l[i] <= '9' && l[i] >= '0' ){
            tmp = tmp*10 + l[i]-48; //convertidor por decenas de string a entero
            dec = 1;
        }
        else {
            if(l[i] == '-') {//si hay un signo negativo
                neg = -1;
            } 
            else if(dec) {//una vez finalizado el numero
                dec = 0;
                n[pos] = tmp*neg;
                pos++;
                tmp = 0;
                neg = 1;

            }
        }
    }
    if(dec)//
      n[pos] = tmp*neg;
      pos++;
    return pos;
}

int main(int argc, char const *argv[])
{
	char linea[1000];
  int c[1000], x[1000];
  while(scanf("%[^\n]",linea)){//escaneo de linea
  	getchar();
      int cant1 = parse(linea, c);//se convierte la cadena de caracteres en un int
      scanf("%[^\n]",linea);
      getchar();
      int cant2 = parse(linea, x);//se convierte la cadena de caracteres en un ont 
     	for (int i = 0; i < cant2; ++i)
     	{
        double sum=0;
     		for (int j = 0; j < cant1; ++j)
     		{
 				   sum=c[j]*pow(x[i],cant1-j-1)+sum;//evaluacion de los valores en el polinomio 
     		}
        cout<<sum<<" ";
     	}
     	cout<<endl;
  }
	return 0;
}
/*
Ejercicio No.5
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/