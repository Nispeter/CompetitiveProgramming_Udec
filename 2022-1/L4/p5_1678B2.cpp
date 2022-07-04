#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in5.txt","r",stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        string s;
        cin>>n>>s;

        int cont = INT_MIN;
        int op = 0, div = 0;
        for (int i = 0; i < n-1; i += 2) {

            if (s[i] != s[i + 1]){
                op++;
                continue;
            }    
            else if (cont != s[i]) 
                div++;
            cont = s[i];        
        }
        div > 1 ? : div = 1;
        cout<<op<<" "<<div<<endl;
    }
}

/*
Tarea No.4
Ejercicio No.5
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/