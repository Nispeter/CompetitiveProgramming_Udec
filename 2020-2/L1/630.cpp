#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>
using namespace std;

bool esAnagrama(string a, string b){//Funcion que detecta si 2 palabras son anagramas
	int aL = a.size();
	int bL = b.size();
	if(aL!=bL)return false;//si son de tamano distino, no son anagrama
	sort(a.begin(),a.end());//se ordenan las letras 
	sort(b.begin(),b.end());
	for (int i = 0; i < aL; ++i)
	{
		if(a[i]!=b[i])return false;
	}//si las nuevas palabras ordenadas son iguales, entonces son anagramas
	return true;
}
int main(int argc, char const *argv[])
{	
	int veces;//cantidad de veces que se realizara el analisis
	cin>>veces;

	while(veces--){//por la cantidad de veces

		int pal;//cantidad de palabras 
		cin>>pal;

		string str;//palabra auxiliar para el escaneo
		vector<string>catalogo;//almacen de strings
		
		int cont = 0;//contador auxiliar para identificar la primera palabra ingresada

		
		for (int i = 0; i < pal; ++i) //Escaneo de palabras
		{
			cin>>str;
			catalogo.push_back(str);
		}

		//Impresion de datos
		while(cin>>str)
		{
			bool tiene = false;//Auxiliar que identifica si tiene anagramas
			int pos = 1;
			if(str=="END")break;//si se escanea END, se termina el analisis
			cout << "Anagrams for: " << str << endl;
			

			for (int i = 0; i < catalogo.size(); ++i)//se visita todo el vector de strings
			{
				if(esAnagrama(catalogo[i],str)){//si tiene anagramas
          			printf("%3d) ", pos);//impresion en 3 caracteres de la posicion en el vector de strings seguido del anagrama.
					cout<<catalogo[i]<<endl;
					tiene = true;
					++pos;
				}
				if(i+1 == catalogo.size() && tiene == false)cout << "No anagrams for: " << str << endl;//sino tiene anagramas
			}
		}
        if(veces)cout<<endl;
	}

	return 0;
}

/*
Ejercicio No.14
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/