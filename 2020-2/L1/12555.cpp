//ANALISIS CODIGO RESCATADO
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    string phrase;
    
    int first;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> first >> phrase;//escaneo de variable 1 y continuacion
        
        double cost = first * 0.5;//calculo del valor base 
        if (phrase.size() >= 4 && phrase[3] != ' ')//funcion clave que determina si el segundo input es valido para el calculo.
            cost += (phrase[3] - '0') * 0.05;//si existe un valor para phrase, este se le suma al valor base.
            
        cout << "Case " << t << ": " << cost << '\n';//impresion de resultados
    }
    
}
/*
Ejercicio No.13
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/Diusrex/UVA-Solutions/blob/master/12555%20Baby%20Me.cpp
*/