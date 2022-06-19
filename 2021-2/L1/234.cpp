#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p,v,a,t;
    int tc=1;
    while(scanf("%d",&p),p){//cantidad de programas 
        vector<int> programs;
        for(int i=0;i<p;i++){
            cin >> v;//escaneo de programas
            programs.push_back(v);
        }
        sort(programs.begin(),programs.end());
        cin >> a;//cantidad de pares 
        vector<pair<int,int>> aligns;
        for(int i=0;i<a;i++){
            cin >> v >> t;//pares de relevancia/alignment points
            aligns.push_back({t,v});
        }
        sort(aligns.begin(),aligns.end());//sort de vectore de pares para usar next_permutation
        vector<int> best(5,INT_MAX);
        vector<int> bestOrder;//vectores auxiliares para definir el mejor orden para la menor diferencia de tiempo
        do {
            vector<int> missTime(5,0);//vector que almacena el tiempo de demora entre canales (inicializado en 0 con maximo 5 espacios)
            int j = 0;//auxiliar de continuidad en arreglo de combinaciones
            int curTime = 0;//contador de tiempo
            for(int i=0;i<aligns.size();i++){//por cada alignmet point 
                while(j<programs.size() && aligns[i].first >= curTime+programs[j]){//por cada programa y que el tiempo del alignment point sea mayor que el tiempo actial
                    curTime += programs[j++];//se agrega el tiempo del siguiente programa 
                }
                int lowerDiff = aligns[i].first - curTime;//diferencia entre el point y el tiempo actual
                int upperDiff = 
                    j<programs.size() ? curTime + programs[j] - aligns[i].first : INT_MAX;//difenrencia entre el tiempo actual y el siguiente point, (en caso de ser el ultimo canal no se agrega)
                missTime[aligns[i].second-1] += min(lowerDiff, upperDiff);//se busca la menor diferencia entre los dos 
            }
            if(missTime < best){//se almacena el mejor tiempo para los programas (mejor entre las permutaciones)
                bestOrder = programs;
                best = missTime;
            }
        } while(next_permutation(programs.begin(),programs.end()));//se busca la siguiente permitacion de programas 
        
        int sum = 0;
        for(auto& i : best) sum+= i;
        
        printf("Data set %d\n",tc++);//indicador del data set 
        printf("Order:");
        for(auto& i : bestOrder) cout << " " << i;//impresion del mejor orden 
        cout << endl;
        printf("Error: %d\n", sum);//impresion de la suma de diferencias en minutos
    }
}

/*
Ejercicio No.6
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/KHvic/uva-online-judge/blob/master/234-Switching%20Channels.cpp
*/