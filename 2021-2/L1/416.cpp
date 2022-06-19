#include <stdio.h>
char g[10][8] = {//posibles numeros para las luces LED
"YYYYYYN",//0
"NYYNNNN",//1
"YYNYYNY",//2
"YYYYNNY",//3
"NYYNNYY",//4
"YNYYNYY",//5
"YNYYYYY",//6
"YYYNNNN",//7
"YYYYYYY",//8
"YYYYNYY",//9
};
int main() {
    int n, i, j, k;//n: cantidad de entradas a evaluar, 3 contadores auxiliares 
    char a[20][8];//almacenamiento de numeros 
    while(scanf("%d", &n) == 1 && n) {//escaneo de secuencia de luces
        for(i = 0; i < n; i++)
            scanf("%s", &a[i]);
        int flag = 0;
        for(i = 9; i >= n-1; i--) {//orden de analisis, sino se cumple una condicion implica que no es un count down
            int bad[10] = {};//array que almacena luces quemadas 
            for(j = 0; j < n; j++) {
                for(k = 0; k < 7; k++) {
                    if(bad[k] && a[j][k] == 'Y')//si es un bad read y se enciende la luz, no cuenta como combinacion valida
                        break;
                    if(a[j][k] == 'N' && g[i-j][k] == 'Y')//si no se activo antes la luz, se cuenta como bad read
                        bad[k] = 1;
                    else if(a[j][k] == 'Y' && g[i-j][k] == 'N')//se busca que la combinacion ingresada coincida con un numero 
                        break;
                }
                if(k != 7)  break;
            }
            if(j == n) {// si se encuentra la combinacion correcta sin falla entre secuencia, se encuentra el resultado
                flag = 1;
                break;
            }
        }
        if(!flag)//si no se encuentra el resultado 
            printf("MIS");
        puts("MATCH");
    }
    return 0;
}


/*
Ejercicio No.9
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://onlinejudgesolution.blogspot.com/2017/05/uva-solution-416-led-test-volume-4.html
*/