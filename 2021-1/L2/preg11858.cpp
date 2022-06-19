#include <iostream>
#include <vector>

using namespace std;

long long count;//contador de swaps

int array1[1000005];//arrays de almacenamiento
int array2[1000005];

void mergesort(int *array, int len, int offset)
{
    if (len > 1)
    {
        int *first = array1 + offset;//creacion de un array auxiliar que contenga los datos de array1
        if (first == array)//si los punteros son iguales entonces first apuntara a la redimencion de array2
            first = array2 + offset;
        
        for (int i = 0; i < len; ++i)//se rellena first con los valores de array
            first[i] = array[i];
        
        int firstLength = len / 2;//posicion inicial del dato en el arreglo
        int secondStart = firstLength, secondLength = len - secondStart;//posicion del inicio del segundo arreglo y tamano del segundo arreglo
        int *second = first + secondStart;//redimenciona el array first para comenzar por second start
        //se dividen los arreglos hasta tener numeros solos
        mergesort(first, firstLength, offset);//aplicacion recursiva de merge sort para el primer array con tamano firstLenght
        mergesort(second, secondLength, offset + secondStart);//aplicacion recursiva de merge sort para el segundo array con tamano secondLenght
        
        int i = 0, j = 0;//contadores auxiliares de posicion
        int pos = 0;//posicion global en el arreglo
        
        int currentCost = count;
        
        while (i < firstLength && j < secondLength)//unir los arrays auxiliares generados segun su orden
        {
            if (first[i] < second[j])//se almacena el primero si es menor
                array[pos++] = first[i++];//codigo hacker donde se asignan los valores primero y luego se incrementan los contadores
            else//sino se almacena el segundo y se cuenta la distancia entre su posicion actual y la origina para agregara como swap
            {
                array[pos++] = second[j++];
                count += firstLength - i;
            }
        }
        
        for (; i < firstLength; ++i, ++pos)//se rellena el array el resto del array
            array[pos] = first[i];
        for (; j < secondLength; ++j, ++pos)
            array[pos] = second[j];
    }
}

int main()
{
    int N;//cantidad de personas
    
    while (cin >> N)
    {
        for (int i = 0; i < N; ++i)//escaneo de datos
            cin >> array1[i];
        
        mergesort(array1, N, 0);//se ordena con merge sort
        
        cout << count << '\n';//impresion de
        count = 0;
    }
}

/*
Ejercicio No.6
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: http://theinfinitytutorial.blogspot.com/2011/12/uva-11858-frosh-week-solution.html
*/


