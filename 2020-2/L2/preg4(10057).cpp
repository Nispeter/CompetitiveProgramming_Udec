#include <stdio.h>
#include <stdlib.h>

int findIdx(int idx, int A[]) {
    int i, sum = 0;
    for(i = 0; ; i++) {//verifica que el la suma de la cantidad de datos sea mayor que la mitad de la cantidad de datos (+1 en el caso de n par)
        sum += A[i];
        printf("%d\n", sum);
        if(sum >= idx)//si es que se cumple lo anterior, se retorna la posicion del primer dato que cumpla
            return i;
    }
}
int main() {
    int n, i, x;//inicializacion de cantidad de valores, contador del for y auxiliar para escanear valores
    while(scanf("%d", &n) == 1) {
        int A[65537] = {};
        for(i = 0; i < n; i++) {//escaneo de datos
            scanf("%d", &x);
            A[x]++;
        }
        int mid, midn, midp, next;
        if(n&1) {//si la cantidad de datos es impar
            mid = findIdx(n/2+1, A);//Encontramos la posicion de el valor que resulta menor en la operacion
            midn = A[mid];//cantidad de repeticiones del dato que da menor valor, en los valores entregados
            midp = 1;//la cantidad de datos totales que son minimos es 1
        } else {//si la cantidad de datos es par se puede dar 
            mid = findIdx(n/2, A);//Encontramos la posicion de el valor que resulta menor en la operacion
            midn = A[mid];//cantidad de repeticiones del dato que da menor valor, en los valores entregados
            next = findIdx(n/2+1, A);//se buscan las otras opciones para el valor A
            if(next != mid) {
                midn += A[next];//se cuentas los otros resultados que cumple la condicion
                midp = next - mid+1;
            } else {
                midp = 1;
            }
        }
        printf("%d %d %d\n", mid, midn, midp);
    }
    return 0;
}

/*
Ejercicio No.4
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://mypaper.pchome.com.tw/zerojudge/post/1322851866
*/