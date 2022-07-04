#include <bits/stdc++.h>

using namespace std;

void printAd( vector<vector<int>> ad, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ad[i][j]<<" ";
        }
        cout<<endl;
    }
    
}



int main(int argc, char const *argv[])
{
    //freopen("in4.txt", "r", stdin);

    int n; 
    cin>>n;

    vector<vector<int>> ad(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        ad[i][a-1] = 1;
        ad[i][b-1] = 1;
    }

    printAd(ad,n);
    int wolves = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> pos;
        vector<int> col;
        vector<int> tam;
        int inDeg = 0;
        

        for (int j = 0; j < n; j++)
        {
            if(ad[j][i] == 0 and j != i){
                pos.push_back(j);
                col.push_back(-1);
                tam.push_back(0);
            }
            else if(ad[j][i]) 
                inDeg++;
        }

        
        for (int j = 0; j < pos.size(); j++)
        {
            for (int k = 0; k < n; k++)
            {
                int minCont = 0;
                if(ad[pos[j]][k]){
                    
                    for (int l = 0; l < n; l++)
                    {
                        bool found = false;
                        for (int m = 0; m < col.size(); m++)
                        {
                            if(col[m] != -1 and col[m] == k){
                                found = true;
                                break;
                            } 
                        }
                        if(found)
                            continue;
                        if(ad[l][k] and l != pos[j] ){
                            minCont++;
                        }
                        
                    }
                    if(tam[j] < minCont ){
                        col[j] = k;
                        tam[j] = minCont;
                    }
                }
            }
            
        }

        for (int j = 0; j < tam.size(); j++)
        {
            if(tam[j] >= inDeg){
                wolves++;
                break;
            }
        }
    }
    cout<<wolves<<endl;

    return 0;
}


/*
Tarea No.5
Ejercicio No.4
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia

OBS: ESTE CODIGO NO FUE ACEPTADO 
No encontre codigo para comentar por lo que escribo una hipotesis de fallo.
Falta verificar la descicion eficiente en base a las intersecciones de desiciones de cada jugador por iteracion
La solicion mas practica que encontre fue utilizar el algoritmo hungaro para cada set, el problema de la posible 
implementacion es que por iteracion de jugador resultaria en conplejidad O(n^3) * O(n^2) lo que no entra en tiempo.
*/