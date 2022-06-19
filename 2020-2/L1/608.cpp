//ANALISIS CODIGO RESCATADO
#include <string>
#include <iostream>
#include <set>

// Using a set is probably overkill for this problem, but most of the code was just copied from my solution to #665

using namespace std;

const int NUM_COINS = 12;
const int NUM_WEIGHINGS = 3;

void ReadSide(set<int>& numbers)
{
    numbers.clear();//se remueven todos los valores del set
    string allCoins;
    cin >> allCoins;//Escaneo de las moendas
    for (string::const_iterator iter = allCoins.begin(); iter != allCoins.end(); ++iter)
        numbers.insert(*iter - 'A');//por cada letra, se inserta su valor en el set numbers
}

void RemoveFrom(set<int>& setRemovedFrom, const set<int>& removedValues)
{
    for (set<int>::const_iterator iter = removedValues.begin(); iter != removedValues.end(); ++iter)
        setRemovedFrom.erase(*iter);//se remueven todos los datos de removedValues en setRemovedFrom 
}

set<int> Union(const set<int>& left, const set<int>& right)
{
    set<int> setsUnion;//se unen dos sets.
    for (set<int>::const_iterator iter = left.begin(); iter != left.end(); ++iter)
    {
        if (right.find(*iter) != right.end())
            setsUnion.insert(*iter);
    }
    
    return setsUnion;
}

set<int> Combine(const set<int>& left, const set<int>& right)
{
    set<int> combined;
    //se combinan los sets left y right
    for (set<int>::const_iterator iter = left.begin(); iter != left.end(); ++iter)
        combined.insert(*iter);
    
    for (set<int>::const_iterator iter = right.begin(); iter != right.end(); ++iter)
        combined.insert(*iter);
        
    return combined;
}

void InterpretResult(const string &result, const set<int>& left, const set<int>&right, set<int>& lessThan, set<int>& greater)
{
    switch (result[0])
    {
    case 'e'://si el resultado es balanceado
        RemoveFrom(lessThan, left);//se descartan todos los valores para ser mas pesados o mas ligeros 
        RemoveFrom(lessThan, right);
        
        RemoveFrom(greater, left);
        RemoveFrom(greater, right);
        break;
        
    case 'u'://si la balanza derecha sube 
        lessThan = Union(lessThan, right);//el lado derecho indica que menos pesado, se une a lessThan
        RemoveFrom(lessThan, left);//se descartan los valores mas ligeros 
        greater = Union(greater, left);//el lado izquierdo indica que es mas pesado, se une a greater
        RemoveFrom(greater, right);//se descartan los valores mas pesados 
        break;
    
    case 'd'://si la balanza derecha baja
        lessThan = Union(lessThan, left);//el lado izquierdo indica que menos pesado, se une a lessThan
        RemoveFrom(lessThan, right);//se descartan los valores mas ligeros 
        greater = Union(greater, right);//el lado derecho indica que es mas pesado, se une a greater
        RemoveFrom(greater, left);//se descartan los valores mas pesados 
        break;
    }
}

int main()
{
    int T;
    cin >> T;//Cantidad de casos
    
    while (T--)
    {
        set<int> lessThan, combined;//creacion de sets auxiliares
        for (int i = 0; i <= NUM_COINS; ++i)
            lessThan.insert(i);
        
        set<int> greater = lessThan;//
        
        set<int> left, right;//creacion de sets derecho e izquierdo
        
        int wrongCoin = -1;
        
        for (int i = 0; i < NUM_WEIGHINGS; ++i)//por 3 veces que se hace la medicion
        {
            ReadSide(left);//Escaneo del lado izquierdo de la balanza
            ReadSide(right);//Escaneo del lado derecho de la balanza
            
            string result;
            cin >> result;//Escaneo del valor del balance
            
            if (wrongCoin == -1)//si no se conoce el valor en el set de la moneda falsa
            {
                InterpretResult(result, left, right, lessThan, greater);//se evalua el resultado
                
                combined = Combine(lessThan, greater);//se combinan todos los valores posibles pesados y ligeros
                
                if (combined.size() == 1)//si la cantidad de valores posibles para la moneda es uno.
                {
                    if (lessThan.size() == 1)//si la moneda resultante es mas ligera
                        wrongCoin = *lessThan.begin(); //la moneda falsa sera el primer valor del set ligero
                    else//si la moneda resultante es mas pesada
                        wrongCoin = *greater.begin();//la moneda falsa sera el primer valor del set pesado
                }
            }
        }
        
        char coin = 'A' + wrongCoin;//transformamos el valor de la moneda falsa del set a letra.
        
        if (lessThan.size() == 1)//si la moneda falsa pertenece al set ligero.
            cout << coin << " is the counterfeit coin and it is light.\n";
        else
            cout << coin << " is the counterfeit coin and it is heavy.\n";
    }
}

/*
Ejercicio No.11
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/Diusrex/UVA-Solutions/blob/master/608%20Counterfeit%20Dollar.cpp
*/