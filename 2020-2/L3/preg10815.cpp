#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("text.txt","r",stdin);

	string text;
	map<string, int>words;

	while(cin>>text){//Escaneo de palabra hasta eof
         
        string aux = "";//string auxiliar que almacena los caracteres de las palabras
		for (int i = 0; i < text.size(); ++i)
		{
            
			if(text[i]>=65 && text[i]<=90)text[i]= text[i]+ 32;//cambiar a minuscula

			if(text[i]<97 || text[i]>122){//si no es una letra, entonces se concidera como fin de palabra
                if(aux!=""){//se almacena la palabra nueva y se limpia la variable auxiliar
                    words[aux]=1;
                    }
                    aux = "";
            }
            else aux+=text[i];//se agrega el caracter a la palabra
		}
        if(aux!="")words[aux]=1;//se ingresa la palabra al map


	}

	map<string,int>::iterator itr;//impresion
	for (itr = words.begin(); itr != words.end(); ++itr)
	{
		cout<<itr->first<<endl;
	}
	return 0;
}

/*
Ejercicio No.5
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/