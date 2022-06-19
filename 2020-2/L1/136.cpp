//ANALISIS CODIGO RESCATADO
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long long numbers[1510];
    
    numbers[0] = 1;
    
    int i2(0), i3(0), i5(0);//inicializador de constructores 
    long long cTwo(2), cThree(3), cFive(5);
    
    int pos = 1;
    
    for (; pos < 1500; ++pos)
    {
        numbers[pos] = min(cTwo, min(cThree, cFive));//determinamos el minimo entre los factores de 2, 3 y 5;
        
        if (cTwo == numbers[pos])
        {
            ++i2;//contador de factores de 2
            cTwo = numbers[i2] * 2;//calculo del nuevo numero potencia de 2
        }
        
        if (cThree == numbers[pos])
        {
            ++i3;//contador de factores de 3
            cThree = numbers[i3] * 3;//calculo del nuevo numero potencia de 3
        }
        
        if (cFive == numbers[pos])
        {
            ++i5;//contador de factores de 5
            cFive = numbers[i5] * 5;//calculo del nuevo numero potencia de 5
        }
    }
    
    printf("The 1500'th ugly number is %lli.\n", numbers[pos - 1]);
}

/*
Ejercicio No.2
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/Diusrex/UVA-Solutions/blob/master/136%20Ugly%20Number.cpp
*/