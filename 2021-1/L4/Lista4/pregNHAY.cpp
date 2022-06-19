#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define d 256 //caracteres en el input alfabetico

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; //valor hash para el patron
	int t = 0; //valor hash para el txt
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < M; i++)//calculo de hash value
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
	for (i = 0; i <= N - M; i++)
	{

		if ( p == t )//check de texto y patron respecto al hash value
		{
			/* Check for characters one by one */
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j]){
					break;
				}
			}

			if (j == M) //impresion de prefix
				cout<< i<<endl;
		}

		// Calculate hash value for next window of text: Remove
		// leading digit, add trailing digit
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;


			if (t < 0)
			t = (t + q);
		}
	}
}

int main()
{
	//freopen("haystack.txt","r",stdin);
	int n;

	while(scanf("%d",&n)!=EOF){//Escaneo de strings

		string text,pat;     
	    cin>>pat>>text;
	 	
	 	if(text.size()<n)continue;
	    char ctext[text.length() + 1]; 
	    char cpat[pat.length() + 1]; 
	 
	    strcpy(ctext, text.c_str()); 
	    strcpy(cpat, pat.c_str()); 
		
		// valor "magico" de analisis matematico
		int q = 101;
		
		search(cpat, ctext, q);
		printf("\n");
	}
	return 0;
}

/*
Ejercicio No.1
Tarea No.4
SPOJ nick: @nisp_2
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
Rabin-Karp algorythm: rescatado de https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
*/