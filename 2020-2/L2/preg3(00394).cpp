#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
 
typedef struct{														//Estructura para almacenar todos los datos de la direccion
    char name[11];
    int B;															//B
    int CD;															//CD
    int D;															//D
    int U[11], L[11], C[11];										//Uper bound, Lower Bound y Cd
} array;
 
vector<array> arrvec;												//vector de la estructura anterior 
vector<array>::iterator arr;
 
int main(){
    int N, R;
    scanf("%d %d", &N, &R);											//escaneo de la cantidad de arrays y de las referencias a arrays  para calcular la direccion
    for(int n=0; n<N; n++){
        array tmp;													//Creacion de array temporal para despues almacenarlo en un vector de arrays 
        scanf("%s %d %d %d", tmp.name, &tmp.B, &tmp.CD, &tmp.D);	//Escaneo de nombre, B , CD y D
        for(int d = 1; d <= tmp.D; d++){
            scanf("%d %d", &tmp.L[d], &tmp.U[d]);					//escaneo de Lower bound y Uper bound
        }
        tmp.C[tmp.D] = tmp.CD;
        for(int d = tmp.D-1; d>0; d--){
            tmp.C[d] = (tmp.U[d+1] - tmp.L[d+1] + 1)*tmp.C[d+1];	//calculo de Cd(Por formula)
        }
        tmp.C[0] = tmp.B;
        for(int d = 1; d <= tmp.D; d++){
            tmp.C[0]=tmp.C[0]-tmp.C[d]*tmp.L[d];					//Calculo de C0(Por formula)
        }
        tmp.L[0] = 1; tmp.U[0] = 1;
        arrvec.push_back(tmp);										//se agrega al vector de arrays 
    }
 
    for(int r = 0; r<R; r++){
        int reference, coord;										//enteros auxiliares que establecen 
        char name[11];
        scanf("%s", name);											//Escaneo del nombre para identificar en el vector de arrays
        for(arr = arrvec.begin(); arr!=arrvec.end(); arr++){
            if(strcmp(name, (*arr).name) == 0){						//Para la seccion del vector donde el nombre del array sea el mismo
                reference = (*arr).C[0];							//Entonces se elige ese como referencia para imprimir
                break;
            }
        }
        printf("%s[", name);										//Impresion del [ y el nombre del array
        scanf("%d", &coord);										//Escaneo de coordenadas
        printf("%d", coord);													
        reference+= (coord) * (*arr).C[1];
        for(int d = 2; d <= (*arr).D; d++){		
            scanf("%d", &coord);									//escaneo de las coordenada 
            printf(", %d", coord);									//impresion de las misma 
            reference+= (coord) * (*arr).C[d];						//calculo final de la physical address
        }
        printf("] = %d\n", reference);								//impresion del ] y la physical addres
    }
    return 0;
}

/*
Ejercicio No.3
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://gist.github.com/ooJerryLeeoo/b81c8c27f9c8221c8b23f48cea494afb
*/