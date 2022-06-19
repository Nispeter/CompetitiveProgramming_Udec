#include <stdio.h>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
int main(void)
{
  int n, permutations;//numero de casos y contador de permutaciones
  int tmp[3];

  set<int> s1, s2, s3;//set de soluciones 
  set<int>::iterator i1, i2, i3;

  for (int i = 0; i <= 20; i++)//incercion de posibles puntajes 
    for (int j = 1; j <= 3; j++) {
      s1.insert(i*j); 
      s2.insert(i*j); 
      s3.insert(i*j); 
    }
  s1.insert(50); //insercion de bullseye
  s2.insert(50);
  s3.insert(50);


  while (EOF != scanf("%d", &n) && n > 0) {

    set<tuple<int, int, int> > combinations;//set para almacenar los trios de puntajes, set evita que se repitan los trios ordenados
    permutations = 0;//contador de permutaciones

    for (i1 = s1.begin(); i1 != s1.end(); i1++)
      for (i2 = s2.begin(); i2 != s2.end(); i2++)
        for (i3 = s3.begin(); i3 != s3.end(); i3++)
          if (*i1 + *i2 + *i3 == n) { // combinacion
            permutations++; // combinacion de dardos que acerto
            tmp[0] = *i1, tmp[1] = *i2, tmp[2] = *i3; 
            sort(tmp, tmp+3); // ordenar la tupla 
            combinations.insert(tuple<int, int, int> (tmp[0], tmp[1], tmp[2]));//si es que no existe se inserta la tupla ordenada
          }

    if (combinations.size()) {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combinations.size());//Impresion de datos
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutations);
    } else {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    }


    printf("**********************************************************************");
    puts("");
  }

  printf("END OF OUTPUT\n");

  return 0;
}


/*
Ejercicio No.2
Tarea No.1
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://geniustanley.github.io/2017/02/08/UVa-735-Dart-a-Mania/
*/