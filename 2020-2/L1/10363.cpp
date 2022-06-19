#include <iostream>
#include <string>

using namespace std;

int WinCon( int tab[3][3], int xy)
{
    if (tab[0][0] == xy && tab[0][1] == xy && tab[0][2] == xy)return 0;//estableciendo condiciones de victoria segun las posiciones del tablero
    if (tab[1][0] == xy && tab[1][1] == xy && tab[1][2] == xy)return 0;
    if (tab[2][0] == xy && tab[2][1] == xy && tab[2][2] == xy)return 0;  
    if (tab[0][0] == xy && tab[1][0] == xy && tab[2][0] == xy)return 0;
    if (tab[0][1] == xy && tab[1][1] == xy && tab[2][1] == xy)return 0;  
    if (tab[0][2] == xy && tab[1][2] == xy && tab[2][2] == xy)return 0;
    if (tab[0][0] == xy && tab[1][1] == xy && tab[2][2] == xy)return 0;
    if (tab[0][2] == xy && tab[1][1] == xy && tab[2][0] == xy)return 0; 
    return 1;
}
int main(int argc, char const *argv[])
{
    int num;
    cin>>num;
    for (int k = 0; k < num; ++k)
    {
        char tablero [3][3];
        int tab[3][3] = {2,2,2,2,2,2,2,2,2};
        int contX = 0;//contador de x
        int contO = 0;//contador de y
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >>tablero[i][j];//escaneo del tablero
                if(tablero[i][j]=='X'){
                    contX++;
                    tab[i][j]=1;

                }
                else if(tablero[i][j]=='O'){
                    contO++;
                    tab[i][j]=0;
                }
            }
        }
        int aux;
        if(contX==contO){//condiciones para que gane X, debido al orden
            aux = WinCon(tab, 'X');
        }
        else if(contX==contO+1){//condiciones para uqe gane O, debido al ordeen
            aux = WinCon(tab, 'O');
        }
        else aux = 0;       
        if (aux) cout << "yes\n";
        else cout << "no\n"; 
    }
        
    return 0;
}
/*
Ejercicio No.7
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/





