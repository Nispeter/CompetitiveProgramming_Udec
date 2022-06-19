#include <iostream>
#include <iostream>
#include <string>

using namespace std;

void primos (long long n){
	long long aux = n;
    while(n%2==0){
        if(n==aux)cout<<"2";
        else cout<<" X 2";
        n = n/2;
    }

	for (long long i = 3; i <= n; i += 2)//verificamos que algun numero entre 3 y n sea primo
	{
		int es = 1;
		for (long long j = 3; j < i; j+=2)//comprobamos que i sea primo dividiendolo por los numeros entre i y 2 
		{
			if (i%j==0 && (i != j || i == n))
			{
				es=0;
				j = i;
			}
		}

		if(es==1){//si es primo
			if(n%i==0){//y si es factor de n
				if(n==aux)cout<<i;
				else cout<<" X "<<i;//imprimimos el valor y ponemos un nuevo valor para n.
				n = n/i;
				i-= 2;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cero:long long n;
	while(n!=0){//verificacion que la entada no sea 0
		cin>>n;
		if(!n)goto cero;
		if(n>1)cout<<n<<" = ";//si es positivo
		else cout<<n<<" = -1 X ";//si es negativo
		primos(abs(n));//llamamos a la funcion que determina los primos
		cout<<endl;
	}

	return 0;
}

/*
Ejercicio No.6
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/