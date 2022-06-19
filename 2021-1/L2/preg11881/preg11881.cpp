#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

double delta = 1e-6;

double fun(vector<double> CF, double IRR){ //Funcion para buscar los ceros

	double NPV = CF[0];
	for (int i = 1; i < CF.size(); ++i)
	{
		NPV+=CF[i]/pow(1 + IRR,i);
	}
	return NPV;
}

double biseccion(vector<double> CF, double lo, double up){//funcion de preg10345.cpp

	double fa = fun(CF,lo);
	double fb = fun(CF,up);

	double med = (lo + up)/2;//si la funcion evaluada en la mitad del intervalo da cero 
	double fm = fun(CF,med);

	if(fa*fb < 0){
		
		if(abs(fm)<1e-7){
			return med;
		}
		else if(fm>1e-7){//si la funcion evaluada en la mitad da mayor que cero
			return biseccion(CF,med,up);//se reasigna el nuevo intervalo para buscar el cero
		}
		else if(fm<-1e-7	){//si la funcion evaluada en la mitad da menor que cer0
			return biseccion(CF,lo,med);//se reasigna el nuevo intervalo para buscar el cero
		}
	}

}

int main(int argc, char const *argv[])
{	
	//freopen("CFIRR.txt","r",stdin);

	while(true){
		vector<double> CF;

		int n = 0;
		double L = -0.99999, U = 1000000;

		cin>>n;
		if(n == 0)break;

		for (int i = 0; i < n+1; ++i)//escaneo de datos
		{
			double aux;
			cin>>aux;
			CF.push_back(aux);
		}

		double res = biseccion(CF,L,U);
		//Debido a la naturaleza de la funcion, siempre tendra un cero, por lo que el caso
		//de "No" o "Too many" no van a ocurrir
		if(res > -1)printf("%.2lf\n",res );

	}
	

	return 0;
}

/*
Ejercicio No.3
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/