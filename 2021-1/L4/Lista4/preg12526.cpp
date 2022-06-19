#include <bits/stdc++.h>

using namespace std ;
void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
#define precision(a) cout << fixed << setprecision(a) 
int ans ;
struct node {//nodo del trie almacena las posibles continuidades del string 
    int occur ;
    int endmark ;
    bool vis ;
    node *next[26] ;
    node() {
        for(int i = 0 ; i < 26 ; i++) 
            next[i] = NULL ;
        occur = 0 ;
        endmark = 0 ;
        vis = 0 ;
    }
} ;
node *root ;
void Insert(string const& s) {//insersion al trie 
    node *cur = root ;
    int len = s.length() ;
    for(int i = 0 ; i < len ; i++) {
        int id = s[i] - 'a' ;
        if(cur->next[id] == NULL) 
            cur->next[id] = new node() ;
        cur = cur->next[id] ;
        cur->occur++ ;
    }
    cur->endmark++ ;
    return ;
}
void DFSonTrie(node *cur , int prev) {//dfs del trie 
    for(int i = 0 ; i < 26 ; i++) {
        if(cur->next[i] != NULL) {
            if(cur->next[i]->occur != prev && cur->next[i]->vis == 0) 
                ans += cur->next[i]->occur ;//incremento de cantidad de segundos
            cur->next[i]->vis = 1 ;//flag de recorrido  
            DFSonTrie(cur->next[i] , cur->next[i]->occur) ;//llamada recursiva para analisar los siguientes prefijos del trie 
        }
    }
    return ;
}
void TrieClear(node *cur) {//destructor de nodos del trie
    for(int i = 0 ; i < 26 ; i++) 
        if(cur->next[i])
            TrieClear(cur->next[i]) ;
    delete cur ;
    return ;
}
int main() {
    fasrerIO() ;
    int n ;
    while(cin >> n) {//
        root = new node() ;
        for(int i = 1 ; i <= n ; i++) {
            string str ;
            cin >> str ;//escaneo e insercion de datos en el trie 
            Insert(str) ;
        }
        ans = 0 ;
        DFSonTrie(root , 0) ;
        precision(2) ;
        double value = ans / (double)n ;//value equivale al valor contado de las palabras siguientes al sufijo buscado partido en el total de palabras 
        cout << value << "\n" ;//se imprimen los valores de escribir las palabras
        TrieClear(root) ;
    }
    return 0 ;
}

/*
Ejercicio No.4
Tarea No.4
SPOJ nick: @nisp_2
Autor: Nicolas Parra Garcia.
Autoria: Rescatado de https://github.com/Khairul-Anam-Mubin/UVa-Solutions/blob/master/12526%20-%20Cellphone%20Typing.cpp
*/