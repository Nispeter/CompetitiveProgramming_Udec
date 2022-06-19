//ANALISIS CODIGO RESCATADO
#include <stdio.h>
#include <math.h>
int gcd(int x, int y) {
    int t;
    while(x%y) {//mientras exista un factor distinto del divisor
        t = x, x = y, y = t%y;//definimos como nuevo dividendo como el resto 
    }
    return y;
}
int main() {
    int n, A[50], i, j;//inicializacion de numero de datos y valores a analizar
    while(scanf("%d", &n) == 1 && n) {
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        int s = n*(n-1)/2, cnt = 0;
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++)//por cada valor escaneado buscamos divisores comunes en el mismo arreglo de datos
                if(gcd(A[i], A[j]) == 1)
                    cnt++;
        }
        if(!cnt)
            puts("No estimate for this data set.");
        else {
            double pi = sqrt((double)6*s/cnt);//calculo final de la estimacion de pi
            printf("%.6lf\n", pi);
        }
    }
    return 0;
}
/*
Ejercicio No.3
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://onlinejudgesolution.blogspot.com/2017/05/uva-solution-412-pi-solution-in-c.html
*/