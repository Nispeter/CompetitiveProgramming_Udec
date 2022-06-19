#include <iostream>
#include <math.h>

using namespace std;
//Inicializacion de la funcion en cuestion
double fun(double x, int p, int q, int r, int s, int t, int u)
{
	return (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u);
}
//Metodo numerico de biseccion para encontrar ceros 
double biseccion(double a, double b, int p, int q, int r, int s, int t, int u){
	double fa = fun(a,p,q,r,s,t,u);
	double fb = fun(b,p,q,r,s,t,u);
	if(fa*fb < 0){
		double temp = (a+b)/2;//si la funcion evaluada en la mitad del intervalo da cero 
		if(abs(fun(temp,p,q,r,s,t,u))<1e-7){
			return temp;
		}
		else if(fun(temp,p,q,r,s,t,u)>1e-7){//si la funcion evaluada en la mitad da mayor que cero
			return biseccion(temp,b,p,q,r,s,t,u);//se reasigna el nuevo intervalo para buscar el cero
		}
		else if(fun(temp,p,q,r,s,t,u)<-1e-7	){//si la funcion evaluada en la mitad da menor que cer0
			return biseccion(a,temp,p,q,r,s,t,u);//se reasigna el nuevo intervalo para buscar el cero
		}
	}

}
//uso del metodo de biseccion para encontrar los ceros de la funcion entre 0 y 1;
int main(int argc, char const *argv[])
{
	ini:int p,q,r,s,t,u;
	if(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)//escaneo de valores de constantes 
	{
		double fa = fun(0,p,q,r,s,t,u);//evaluacion de la funcion en extremos del intervalo
		double fb = fun(1,p,q,r,s,t,u);
		if(fa == 0){//caso especial para fa = 0
			printf("0.0000\n");
		}
		else if(fb == 0){//caso especial para fb = 0
			printf("1.0000\n");
		}
		else if(fa*fb<0){//si el intervalo es valido para las constantes ingresadas
			printf("%.4lf\n",biseccion(0,1,p,q,r,s,t,u));
		}
		else{//sino es valido 
			printf("No solution\n");
		}
		goto ini;
	}
	return 0;
}

/*
Ejercicio No.2
Tarea No.2
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/
