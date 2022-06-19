#include <bits/stdc++.h>
#define LL long long
using namespace std;

int val[10001],wt[10001];//val[]: valor de cada item, wt[]: precios de cada item

int kp[101][10001],cap,n,m; //kp: matriz de maximizacion del knapsack, numero de items

int knapsack(int i,int w)
{
    if(w>cap && w-200>cap)//si el precio acumulado sobrepasa la capacidad maxima por mas de 200 entonces k[i][w] no es valido
        return -INT_MAX;
    if(w>cap && cap<1800)//si el precio no supera los 1800 pero supera la capacidad maxima, entonces no es valido
        return -INT_MAX;
    if(i==m)//si se esta evaluando el utlimo dato 
    {
        if(w>cap && w<=2000) //si el precio supera el maximo y no los 2000, no se entrega el bono de reembolso
            return -INT_MAX;
        return 0;
    }

    if(kp[i][w]!=-1)//
        return kp[i][w];
    //almacenamiento de valores antes de retornar, conciderando el maximo entre elegir el dato actual o no eligiendolo
    kp[i][w]=max(knapsack(i+1,w),val[i]+knapsack(i+1,w+wt[i]));
    return kp[i][w];
}

int main()
{
    LL i,j,k,a,b,c,cnt=0,id=1,l,t,x,y,mx=0;

    while(cin>>cap>>m)//cap: dinero maximo, m: numero de items
    {
        memset(kp,-1,sizeof kp);//memory set para el array de maximizacion
        for(i=0;i<m;i++)
        {
            cin>>wt[i]>>val[i];//escaneo de pesos y valores 
        }

        cout<<knapsack(0,0)<<endl;//llamada a algoritmo de knapsack

    }
    return 0;
}

/*
Ejercicio No.5
Tarea No.4
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:https://discordapp.com/channels/@me/819235895181180978/908834712762605598
*/