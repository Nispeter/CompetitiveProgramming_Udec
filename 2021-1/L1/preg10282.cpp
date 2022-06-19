#include <cstdio>
#include <iostream>
#include <map>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("sample.txt","r",stdin);
	map<string,string>dict;

	while(true){

		char word[100];
		char a[11],b[11];
		fgets(word,30,stdin);

		sscanf(word,"%s %s",a,b);
		if(word[0] == '\n')break;
		string str(b);
		string s(a);
		//cout<<s<<" "<<str<<endl; 
		if(dict[b] == "")dict[str] = s;
	}

	char auxB[100];
	while (scanf("%s",auxB) != EOF){
		if(dict[auxB]!= "")cout<<dict[auxB]<<endl;
		else cout<<"eh"<<endl;
	}
	return 0;
}

/*
Ejercicio No.2
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/