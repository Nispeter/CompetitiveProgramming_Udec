#include <cstdio>
#include <cstring>
#define N 250001

using namespace std;

struct node {//nodo del diccionario
    int children[ 26 ];
    bool isword;
};

int trnc;
node trie[ N ];

void init() {
    trnc = 1;
    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < 26; ++j ) {
            trie[ i ].children[ j ] = 0;
        }
      trie[ i ].isword = false;
    }
}

void add( char* word, int len ) {
    int i, curNode = 1, nextNode;
    for ( i = 0; i < len; ++i ) {
        nextNode = trie[ curNode ].children[ word[ i ] - 'a' ];//busqueda del final del prefijo para agregar un caracter 
        if ( nextNode == 0 ) {
            trnc++;
            trie[ curNode ].children[ word[ i ] - 'a' ] = trnc;
            curNode = trnc;
        }
        else {
            curNode = nextNode;
        }
    }
    trie[ curNode ].isword = true;
}

void dfs( char* word, int pos, int curNode ) {//busqueda en profundidad que entrega los prefijos siguientes al string buscado 
    if ( trie[ curNode ].isword ) {//si se llega al final de un prefijo, se imprime
        printf( "%s\n", word );
    }
    char n[ 25 ];
    for ( int i = 0; i < 26; ++i ) {//se recorre en profundidad todas las posibles palabras apartir de
        if ( trie[ curNode ].children[ i ] != 0 ) {
            word[ pos + 1 ] = i + 'a';
            word[ pos + 2 ] = '\0';
            dfs( word, pos + 1, trie[ curNode ].children[ i ] );
        }
    }
}

bool check( char* word, int len ) {
    int i, curNode = 1;
    for ( i = 0; i < len; ++i ) {
        curNode = trie[ curNode ].children[ word[ i ] - 'a' ];
        if ( curNode == 0 ) {
            return false;
        }
    }
    bool found = false;
    for ( i = 0; i < 26; ++i ) {
        if ( trie[ curNode ].children[ i ] != 0 ) {
            word[ len ] = i + 'a';
            word[ len + 1 ] = '\0';
            dfs( word, len, trie[ curNode ].children[ i ] );
            found = true;
        }
    }
    return found;
}

void remove( char* word, int len ) {
    int i, curNode = 1;
    for ( i = 0; i < len; ++i ) {
        curNode = trie[ curNode ].children[ word[ i ] - 'a' ];
    }
    trie[ curNode ].isword = false;
}

int main() {
    int i, n;
    char s[ 30 ];
    scanf( "%d", &n );//numero de palabras en el diccionario
    init();//inicializacion del trie que almacena los sufijos del diccionario
    for ( i = 0; i < n; ++i ) {//escaneo de palabras
        scanf( "%s", s );
        add( s, strlen( s ) );
    }
    scanf( "%d", &n );//casos de busqueda
    for ( i = 1; i <= n; ++i ) {
        scanf( "%s", s );//palabras de busqueda
        printf( "Case #%d:\n", i );
        if ( !check( s, strlen( s ) ) ) {//busqueda de palabra en el diccionario
            printf( "No match.\n" ); 
        }
    }
    return 0;
}

/*
Ejercicio No.6
Tarea No.4
SPOJ nick: @nisp_2
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/vitsalis/SPOJ/blob/master/DICT/dict.cpp
*/