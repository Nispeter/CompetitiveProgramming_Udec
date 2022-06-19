#include <bits/stdc++.h>

using namespace std;



void anagrama(int opnumber, string anagram1, string word1, string stack, string operaciones,string word, string anagram, int length)
{
  if(opnumber == (length*2)){//caso en que la cantidad de operaciones del stack sea igual al doble del largo de la palabra
    if(anagram1 == anagram)//caso de que el anagrama formado despues de las operaciones sea igual al output correspondiente
      cout << operaciones << "\n";
    return;//si de corroboro que las iteraciones en el stack, resutaron en una palabra igual al output esperado, se imprime
  }

  if(word1.length()!=0){//si el largo de la palabra auxiliar es distinto de cero 

    string opAux = "i";//input a stack distintos dependiendo si es el primer dato de entrar o no.
    if(opnumber!=0)
      opAux = " i";
    string newAnagram1 = "";

    for (int i = 1; i < word1.size(); ++i)//creacion de string auxiliar que reduce la palabra a evaluar en la siguente iteracion
    {
      newAnagram1+=word1[i];
    }
    //se llama a la misma funcion, pero se aumenta las operaciones, se modifica la palabra y se le agrega un in al stack
    anagrama(opnumber + 1, anagram1, newAnagram1, stack + word1[0], operaciones + opAux,word,anagram,length);
  }
  
  int len = stack.length();
  if(len != 0 && stack[len - 1] == anagram[anagram1.length()]){//si la longitud del stack es distinta de cero y la ultima palabra del stack coincide con la ultima palabra del anagrama auxiliar
    //esto diferencia las distintas lineas de busqueda entre iteraciones, descartando posibles ramificaciones erroneas
    string newWord1 = "";

    for (int i = 0; i < stack.length()-1; ++i)
    {
      newWord1+=stack[i];
    }//nuevo string para evaluar la palabra modificada en la siguente iteracion
    //se llama a la misma funcion, pero se aumentas las operaciones, se modifica de vuelta el anagrama a analizar, junto con la palabra modificada y se le agrega un out al stack.SS 
    anagrama(opnumber + 1, anagram1 + stack[len - 1], word1,newWord1, operaciones + " o",word,anagram,length);
  }
}

int main(void)
{
  string word, anagram;
  while(cin >> word >> anagram)//escaneo de datos
  {
    int length = word.length();

    printf("[\n");

    if(length == anagram.length()){
      string opnumber = "",anagram1 = "",stack = "";//strings auxiliares.
      anagrama(0, opnumber, word, anagram1, stack,word,anagram,length);
      //se ingresa el contador de operaciones, y 4 strings que representan  el anagrama que se forma por la operacion del stack,
    //la palabra original, la palabra formada por las operaciones del stack y el stack. 
    }   

    printf("]\n");
  }
  return 0;
}

/*
Ejercicio No.5
Tarea No.2
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:Autoria:https://github.com/isanchez-aguilar/UVa-Solutions/blob/master/732%20-%20Anagrams%20by%20Stack.cpp

*/