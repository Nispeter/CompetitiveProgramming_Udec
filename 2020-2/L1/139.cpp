//ANALISIS DE CODIGO RESCATADO
#include <iostream>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    unordered_map<string,pair<string,int> > table;
    string code;

    while(cin >> code, code != "000000") {//mientras code sea distinto de 000000, se escanea code
        string name;
        cin.ignore(1, ' ');//se ingnora el espacio
        getline(cin, name, '$');//se escanea el nombre y el simbolo $

        int price;
        cin >> price;//se escanea el precio de la llamada

        table[code] = make_pair(name, price);//se mapea el codigo sin ordenar a los nombres y precios escaneados 
    }

    while(cin >> code, code != "#") {//mientras code sea distinto de #, se escanea code
        int minutes;
        cin >> minutes;

        bool isFound = false;//variable que determina si se reconoce como codigo valido
        pair<string, pair<string,int> > pr;

        for(auto& x : table) {//loop basado en rango que empeiza por x
            if(code.find(x.first) == 0) {//se busca que el primer xtring de table en x coincida con code
                int subscriberCodeLength = code.length() - x.first.length();//variable que detecta la longitud de code 

                if((code[0] == '0' && code[1] == '0' && 4 <= subscriberCodeLength && subscriberCodeLength <= 10) ||//si los codigos cionciden
                    (code[0] == '0' && code[1] != '0' && 4 <= subscriberCodeLength && subscriberCodeLength <= 7)) {

                    isFound = true;//se encontro la direccion y por ende la llamada esta catalogada
                    pr = x;//pr se establece como el map encontrado
                    break;
                }
            }
        }

        cout.precision(2); fixed(cout);//Establecemos la impresion en notacion fixed point y la presicion de los decimales.
        cout.unsetf(ios::right);//Establecemos las caracteristicas deseadas en el tipo de impresion
        cout.setf(ios::left);//Establece las impresiones a la izquierda

        if(isFound) {//si el codigo es valido
            cout << setw(16) << code//impresion de datos en orden con sus respectivas distancias gracias a setw()
                << pr.second.first
                << setiosflags(ios::right) << setw(51 - 16 - pr.second.first.length()) << code.substr(pr.first.length())//separa la impresion con un mask espesifico y luego se le pone la distancia entre 
                << setw(5) << minutes
                << setw(6) << pr.second.second/100.0
                << setw(7) << minutes * pr.second.second / 100.0 << '\n';
        }
        else if(code.front() != '0') {//si el costo de la llamada es 0
            cout << setw(16) << code//impresion de datos en orden con sus respectivas distancias gracias a setw()
                << "Local"
                << setiosflags(ios::right) << setw(51 - 16 - 5) << code
                << setw(5) << minutes
                << setw(6) << "0.00"//impresion de valores por defecto de las llamadas locales
                << setw(7) << "0.00" << '\n';
        }
        else {//si el codigo no es valido
            cout << setw(16) << code//impresion de datos en orden con sus respectivas distancias gracias a setw()
                << "Unknown"//impresion de valores por defecto de las llamadas desconocidas
                << setiosflags(ios::right) << setw(51 - 16 - 7 + 5) << minutes
                << setw(6+7) << "-1.00" << '\n';
        }
    }

    return 0;
}

/*
Ejercicio No.12
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/shahed-shd/Online-Judge-Solutions/blob/master/UVa-Online-Judge/139%20-%20Telephone%20Tangles.cpp
*/
