#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int a; 
    int lugar = 0;
    cin>>a;//cantidad de veces

    map<string , int> lista;
    for (int i = 0; i < a; ++i)
    {
        string pais;//escaneo del pais
        cin>>pais;
        getchar();
        char aux[75];
        scanf("%[^\n]",aux);//se ingora el resto de la linea
        int cont=0;
        lista[pais] += 1; //se mapea el pais y se le suma 1 
    }
    map <string,int>::iterator itr;//iterador del map
    for ( itr = lista.begin(); itr != lista.end(); ++itr)
    {
         cout << itr->first << " " << itr->second << '\n';//se imprime el pais y la cantidad
    }
    return 0;
}
/*
Ejercicio No.8
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/
