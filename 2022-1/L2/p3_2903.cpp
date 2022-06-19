#include <bits/stdc++.h>

using namespace std;

int main(){
    string aux;
    cin>>aux;

    string s1,s2;
    for (int i = 0; i < aux.size(); i++)
    {
        s1+=aux[i];
        if(aux[i] == '.')
            break;
    }
    s2 += aux[aux.size()-2];
    s2 += aux[aux.size()-1];

    int a,b;
    a = atoi(s1.c_str());
    b = atoi(s2.c_str());
    double r = a*100 + b;
    
   //cerr<<a<<" "<<b<<" r "<<r<<endl;
    
    double c=36000;
    while(r != 0){
        double tmp = r;
        r=fmod(c,r);
        c=tmp;
    }
    double res = 36000/c;
    cout<<(int)res<<endl;

    return 0;
}

/*
Tarea No.1
Ejercicio No.3
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/