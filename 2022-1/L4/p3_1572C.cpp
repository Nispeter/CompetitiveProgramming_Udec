#include <bits/stdc++.h>
 
int N;
int A[5000];//pixeles originales 
int dp[5000][5000]; //equivale a la cantidad de operaciones a usar
int col[5000], next[5000], prev[5000];//auxiliares para calcular cuandas operaciones nos ahorramos 
 
int main() {
    int T; scanf("%d", &T);//casos
    while (T--) {
        scanf("%d", &N);//pxeles
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        std::fill(col, col + N + 1, -1);
        std::fill(next, next + N + 1, -1);
        for (int i = 0; i < N; ++i) {//posiciones donde se repite un color en el futuro
            if (col[A[i]] >= 0) next[col[A[i]]] = i; //(posicion desde 0 a N-1)
            col[A[i]] = i;
        }
        std::fill(col, col + N + 1, -1);
        std::fill(prev, prev + N + 1, -1);
        for (int i = N - 1; i >= 0; --i) { //posiciones donde se repite un color en el pasado 
            if (col[A[i]] >= 0) prev[col[A[i]]] = i;  // (posicion desde N-1  a 0 )
            col[A[i]] = i;
        }
        for (int i = 0; i <= N; ++i) std::fill(dp[i], dp[i] + N + 1, 0);
        for (int i = 0; i + 1 < N; ++i)//estado inicial con colores distintos 
            dp[i][i + 2] = (A[i] != A[i + 1]); //si no hay dos colores iguales seguidos 
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                dp[i][i + len] = dp[i + 1][i + len - 1] + (A[i] == A[i + len - 1] ? 1 : 2); //se completa el dp respecto a los colores distintos  en posicion 
                for (int j = next[i]; j < i + len - 1 && j != -1; j = next[j]) { //para las repeticiones en el "pasado" se asigna a la posicion actual mas el fin del la secuencia de color len
                    dp[i][i + len] = std::min(dp[i][i + len], dp[i][j + 1] + dp[j + 1][i + len] + (A[i] == A[i + len - 1] ? 0 : 1)); //las operaciones minimas entre la iteracion actual y la actual mas la suma de la anterior, verificando si se repite el pixel 
                }
                for (int j = prev[i + len - 1]; j > i && j != -1; j = prev[j]) {//para las repeticiones del "futuro" se asigna a la posicion actual mas el fin de la secuenciia de color len 
                    dp[i][i + len] = std::min(dp[i][i + len], dp[i][j] + dp[j][i + len] + (A[i] == A[i + len - 1] ? 0 : 1)); //las operaciones minimas entre la iteracion actual y la actual mas la suma de la anterior, verificando que no sean colores iguales al finlar de la secuencia 
                }
            }
        }
        // printf(": %d\n", dp[0][2]);
        // printf(": %d\n", dp[2][3]);
        printf("%d\n", dp[0][N]);
    }
}

/*
Tarea No.4
Ejercicio No.3
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria: https://codeforces.com/contest/1572/submission/129194484
*/