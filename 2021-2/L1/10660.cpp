#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;
 //variables globales auxiliares
int nTest;//test cases
 
int nNonNull;//cantidad de poblacion
int areaPopulation[25], distanceSumMin;//mapa de poblacion, contador de suma minima
int officeI = 0, officeArea[5], officeAreaSol[5];
 
void solve(int areaL) {
    if (officeI < 5) {//verifica que la cantidad de oficinas sea menor que 5
        for (int areaI = areaL; areaI < 25; ++areaI) {
            // backtrack
            officeArea[officeI++] = areaI;
            solve(areaI + 1);
            --officeI;
        }
    } else {
        // calculo de distancias minimas 
        int distanceSum = 0;
        for (int areaI = 0; areaI < 25; ++areaI)//analisis de cada tile
            if (areaPopulation[areaI] > 0) {//mientras exista poblacion en el area
                int minDistance = INT_MAX;
                for (int officeI = 0; officeI < 5; ++officeI)//se calcula la distancia hacia el puesto conciderando la poblacion * (distancia en x + distancia en y)
                    minDistance = min(minDistance, areaPopulation[areaI] * (abs(areaI % 5 - officeArea[officeI] % 5) + abs(areaI / 5 - officeArea[officeI] / 5)));
                distanceSum += minDistance;//se agrega al contador de sitancia minima
            }
        // minimizar 
        if (distanceSum < distanceSumMin) {
            distanceSumMin = distanceSum;//si se encuentra una distancia menor, entonces se ha encontrado la solucion buscada
            for (int i = 0; i < 5; ++i)
                officeAreaSol[i] = officeArea[i];
        }
    }
}
 
int main() {
    cin >> nTest;//test cases
    for (int testI = 0; testI < nTest; ++testI) {
    	//cantidad de poblacion
        cin >> nNonNull;
        for (int i = 0; i < 25; ++i)//seteo de mapa de ciudad en 0
            areaPopulation[i] = 0;
        for (int areaI = 0; areaI < nNonNull; ++areaI) { //escaneo de coordenadas de poblacion
            int x, y;
            cin >> x;
            cin >> y;
            cin >> areaPopulation[x * 5 + y];
        }
        // solve
        distanceSumMin = INT_MAX;//distancia minima a superar
        solve(0);//lamada a funcion de calculo
        for (int i = 0; i < 5; ++i)
            cout << officeAreaSol[i] << ((i == 4) ? "\n" : " ");//impresion  de posiciones de oficinas
    }
    return 0;
}

/*
Ejercicio No.3
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:https://gsourcecode.wordpress.com/2012/02/01/uva-10660/
*/

