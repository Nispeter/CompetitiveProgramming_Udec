#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{

    int test,i,j,len;//variables auxiliares
    string s;//texto a analizar
    int got;
    scanf("%d", &test);
    while(test--){
        cin>>s;
        len = s.length();
        got = true;
        for(i=1;i<=len;i++){
            if(len%i!=0)continue; //si el string total no es divisible en el patron entonces se analiza el siguiente patron
            for(j=i;j<len;j++)
                if(s[j]!=s[j%i]){//se ve si la letra en la posicion j%i es similar al del string, siendo j%i la siguiente iteracion del patron
                    got = false;//si son distintas entonces no se encuentra el patron para una seccion del string por lo que se expande el patron
                    break;
                }
            if(got)break;//si son iguales entonces se encuentra el patron de menor tamano
            got = true;
        }
            printf("%d\n",i);
        if(test)printf("\n");
    }
    return 0;
}

/*
Ejercicio No.2
Tarea No.5
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/shahidul2k9/problem-solution/blob/master/uva%20online%20judge/455%20-%20Periodic%20Strings.cpp
*/