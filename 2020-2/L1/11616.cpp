#include <iostream>
#include <string>

using namespace std;
int rN(string num){//funcion que convierte de romano a arabico
	int sum = 0;
	int res[1000];
	for (int i = 0; i < num.size(); ++i)
	{
		switch(num[i]){//Se asigna el valor a  la suma en arabico, dependiendo de la letra
			case 'I':
				res[i]=1;
				if(num[i+1]=='V')res[i]=4,num[i+1]=0;//caso IV
				if(num[i+1]=='X')res[i]=9,num[i+1]=0;//caso IX
				break;
			case 'V':
				res[i]=5;
				break;
			case 'X':
				res[i]=10;
				if(num[i+1]=='L')res[i]=40,num[i+1]=0;//caso XL
				if(num[i+1]=='C')res[i]=90,num[i+1]=0;//caso XC
				break;
			case 'L':
				res[i]=50;
				break;
			case 'C':
				res[i]=100;
				if(num[i+1]=='D')res[i]=400,num[i+1]=0;//caso CD
				if(num[i+1]=='M')res[i]=900,num[i+1]=0;//caso CM
				break;
			case 'D':
				res[i]=500;
				break;
			case 'M':
				res[i]=1000;
				break;
			default:
				res[i]=0;
		}
	}
	for (int i = 0; i < num.size(); ++i)
	{
		sum += res[i];
	}
	return sum;
}
string nR(string num){//fincion que convierte de arabico a romano
	int n = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		n = 10*n + (num[i]-'0');
	}
	string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};//todas las posibles combinaciones de letras para formar numeros especificos.
	int equiv[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};//posibles numeros especificos
	string pal = "";
	for (int i = 0; i < 13; ++i)//en orden acendente, se le resta al numero arabico su contraparte romana.
	{
		while(n-equiv[i]>=0){//mientras la cantidad en romano no iguale a la cantidad en arabico
			n-=equiv[i];
			pal= pal + roman[i];
		}
	}
	return pal;
}
int main(int argc, char const *argv[])
{
	string linea;
  	while(cin>>linea){
  		if(linea[0]>'0'&&linea[0]<='9')cout<<nR(linea)<<endl;
		else cout<<rN(linea)<<endl;
  	}

	return 0;
}

/*
Ejercicio No.9
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/