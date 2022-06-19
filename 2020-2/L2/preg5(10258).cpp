#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define long long LL
using namespace std;
 
struct Team//Estructura de equipos que almacena:
{
    Team(int TN, bool P)
    {
        TeamNumber = TN;
        Participating = P;
    }
    int nSolved;//numero de respuestas resueltas
    int PenaltyTime;//la penalizacion del tiempo
    int TeamNumber;//el  numero del equipo
    bool Participating;//auxiliar que verifica si el equipo esta participando o no.
};
 
bool compareTeams(Team T1, Team T2)//funcion que compara 2 quipos ,la cual dentro de un sort, ordenara los equipos dependiendo de 
{//el numero de espuestas resueltas, penlaizacion de tiempo o numero de equipo
    if (T1.nSolved != T2.nSolved)//si la cantidad de resultados correctos es distinto, se evalua por estos.
        return T1.nSolved > T2.nSolved;
 
    if (T1.PenaltyTime != T2.PenaltyTime)//si las cantidades de penalisacion son  distintos, se evalua por estos
        return T1.PenaltyTime < T2.PenaltyTime;
 
    return T1.TeamNumber < T2.TeamNumber;//caso por defecto se evalua por numero de equipo
    //dependiendo del valor de retorno,  y el criterio de comparacion, se reordenaran los quipos dentro del vector.
}
int main ()
{
    int N;
 
    scanf("%d\n",&N);//Escaneo de numero de veces a evaluar
 
    for (int i=0; i<N; i++)
    {
        scanf("\n");
        vector<pair<char,int> > TeamsMessages[101][10];//array bidimension de vectores de pares que almacena los mensajes de cada problema para cada equipo 
        vector<Team> Teams;//vector que almacena los equipos validos
 
        for (int i=0; i<101; i++)//creacion de un vector de equipos que define cuales participaran y cuales no
            Teams.push_back(*(new Team(i, false)));//creacion de un nuevo objeto equipo
 
        char input [100];//auxiliar de input para analizar posteriormente
 
        while(fgets(input,100,stdin) != NULL)
        {
            if (input[0] == '\n') break;//si se escanea un enter significa que termianron los resultados de las preguntas a evaluar
            stringstream s(input);
            int TeamNumber,ProblemNumber;
            pair<char,int> Message;//par que almacena momentaneamente el mensaje de evaluacion y el timpo
            char Type;
            s >> TeamNumber >> ProblemNumber >> Message.second >> Message.first;//separacion del input en las variables respectivas
            Teams[TeamNumber].Participating = true;//Escaneo de los equipos que van a partisipar
            if (Message.first == 'C' || Message.first == 'I')//si el mensaje de la respuesta es correcto o incorrecto, se agrega como respuesta a conciderar para calcular el puntaje 
                TeamsMessages[TeamNumber][ProblemNumber].push_back(Message);
 
        }
 
        for (int j=0; j<Teams.size(); j++)
        {
            Teams[j].PenaltyTime = 0;//inicializacion de contadores de equipo
            Teams[j].nSolved = 0;
            for (int k=1; k< 10; k++)
            {
                vector<pair<char,int> > Messages = TeamsMessages[j][k];//vector de pares para almacenar el mensaje y la penalizacion de timepo individual
                int PenaltyTime=0;//auxiliar para el calculo de la penalizacion de tiempo
 
                for (int h=0; h< Messages.size(); h++)
                {
                    if (Messages[h].first == 'I') PenaltyTime+= 20;//Calculo de la penalizacion por tiempo
                    else if (Messages[h].first == 'C')
                    {
                        PenaltyTime += Messages[h].second;//Incremento de penalizacion por tiempo segun el par
                        Teams[j].nSolved++;//Incremento de preguntas resueltas
                        Teams[j].PenaltyTime += PenaltyTime;
                        break;
                    }
                }
            }
        }
 
        sort(Teams.begin(), Teams.end(), compareTeams);//ordena el vector teams comparando cada dos equipos por su numero.
    //compareTemas, acepta dos elemntos y retorna un bool que define si la comparacion paso el primer argumento
        for (int i=0; i<Teams.size(); i++)//impresion de el numero de equipo, numero de respuestas resueltas, y penalizacion de tiempo
            if (Teams[i].Participating) printf("%d %d %d\n", Teams[i].TeamNumber, Teams[i].nSolved, Teams[i].PenaltyTime);
 
        if (i != N-1) printf("\n");
    }
 
    return 0;
}

/*
Ejercicio No.5
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:https://uhunt.onlinejudge.org/id/1171308
*/