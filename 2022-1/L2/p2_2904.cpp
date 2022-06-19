#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{

    //freopen("p2.txt","r",stdin);

    long long int  acu=0;
    long long int  n, meta,salida;
    cin>>n;

    set<long long int > s;
    vector<long long int > v(n+1);

    v[0]=0;
    s.insert(v[0]);
    for (int  i = 1; i <= n; ++i)
    {
        long long int aux;
        cin>>aux;
        v.push_back(aux);
        acu +=aux;
        s.insert(acu);
    }

    if(acu%2 != 0){
        cout<<"N"<<endl;
        return 0;
    }
    meta=acu/2;
    salida=0;acu=0;

    for (int  i = 1; acu<meta; ++i)
    {
        long long int sum = acu + meta;
        if(s.find(sum)!=s.end()){
            salida++;
        acu+=v[i];
    }
    if(salida<2){
        cout<<"N"<<endl;
    }else{
        cout<<"Y"<<endl;
    }

    return 0;
}

/*
Tarea No.1
Ejercicio No.2
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/