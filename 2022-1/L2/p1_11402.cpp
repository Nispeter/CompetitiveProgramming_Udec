// Jair Said Hernandez Reyes.
// Segment Tree + Lazy Propagation.
// In General we have f(x) = a where a is the answer for every sub segment on tree, in this case f(x) = st[x].
// We also need a G(x) = R where G is a function that takes any n E Nodes and indicates what to do next, in this particular case G = lazy.
// G actually works as a flag.
// notice that we need to create function that handles transitions 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll st[5024000], A[5024000], N, T, M, X;
char lazy[5024000];
string in;
const ll INF = 1LL<<60;
void build(ll p, ll L, ll R){//construccion de arboles 
	lazy[p] = 'X';//lazy propagation tree
	st[p]   =  0;//segment tree
	if(L == R)
		st[p] = A[L];
	else{//construccion recursiva 
		build( (2 * p), L, (L + R) >> 1);
		build( (2 * p) + 1, ((L + R) >> 1) + 1, R);
		ll dx = st[2 * p], dy = st[2 * p + 1];
		st[p] = dx + dy;
	}
}
void changeState(ll p){//flags que indican el tipo de  update a hacer en el arbol
	if(lazy[p] == 'I'){
		lazy[p] = 'X';
		return;
	}
	if(lazy[p] == 'E'){
		lazy[p] = 'F';
		return;
	}
	if(lazy[p] == 'F'){
		lazy[p] = 'E';
		return;
	}
	if(lazy[p] == 'X'){
		lazy[p] = 'I';	
		return;
	}
}
void propagate(ll p ,ll  R,ll  L){//propagacion de acuerdo a las flags 
	if(lazy[p] == 'E'){//suma de piratas en nodo= 0 en rango
		st[p] = 0;
	}
	if(lazy[p] == 'F'){//suma de piratas en nodo = actualizada anterior + 1
		st[p] = (R - L + 1);
	}
	if(lazy[p] == 'I'){//invertir valores
		st[p] = R - L + 1 - st[p];
	}
	if(L != R){
		if(lazy[p] == 'I'){ 
			changeState(p*2);
			changeState((p*2)+ 1);
		}else{//se agrega la operacion de actualizacion al lazy "tree"
			lazy[ (p*2) + 1 ] = lazy[p];
			lazy[ p*2 ] = lazy[p];
		}
	}
	lazy[p] = 'X';//sin actualizaciones que realizar en st[]
}
ll Q(ll p, ll L, ll R, ll i, ll j){
	if(lazy[p] != 'X'){//propagacion en caso de que no se hayan actualizado antes 
		propagate(p, R, L);
	}
	if( R < i || L > j) return 0;//se decuende a travez de las hojas del arbol
	if( L >= i && R <=j) return st[p];//hasta encontrar el rango desado
	ll a = Q(p * 2, L , (L + R) >> 1, i , j);
	ll b = Q(p * 2 + 1, ((L + R) >> 1) + 1, R, i , j);
	/*if(a == -1) return b;
	if(b == -1) return a;*/
	return (a + b);//suma por rango recursiva 
}

void U(ll p, ll L, ll R, ll a, ll b, char v){
	// update de nodo 
	if(lazy[p] != 'X'){
		propagate(p, R, L);
	}
	if(L > b || R < a) return;
	if(L >= a && R <= b){
		// actualizacion de segmento para que pertenezca a la solucion general 
		if(v == 'E'){//nodo de acumulacion = 0
			st[p] = 0;
		}
		if(v == 'F'){//nodo de acumulacion = suma + 1
			st[p] = (R - L + 1);
		}
		if(v == 'I'){
			ll len = R - L + 1;
			st[p] = len - st[p];
		}
		if(L != R){//si el rango es mas grande que 0, se cambian los estados
			if(v == 'I'){//en caso de inversion se usa una funcion distinta
				changeState((2*p)+1);
				changeState(2*p);
			}else{//en otro caso se usa lazy propagation
				lazy[2*p] = v;
				lazy[(2*p)+1] = v;
			}
		}
		return;
	}
	ll m = (L + R) >> 1;//actualizacion de nodo actual
	U(p*2, L, m, a , b, v);//update de nodos superiores 
	U(p*2 + 1, m + 1, R, a , b, v);
	st[p] = st[2*p]+ st[(2*p) + 1];//actualizacion de nodos en el arbol
}
int main(){
	cin >> T;// test cases
	ll idx, Qu;
	for(ll i = 1; i <= T; i++){
		cout << "Case "<<i<<":"<<endl;//caso actual
		cin >> M;//lineas de pares 
		in ="";
		idx = 0;
		X = 0;
		memset(A, sizeof(A),0);
		for(ll j = 0 ; j < M; j++){
			cin >> X;//repeticiones 
			cin >> in;//linea de piratas 
			for(ll k = 0; k < X; k++){
				for(ll r = 0; r < in.size(); r++){//almacenamiento en el array de piratas 
					if(in[r] == '0')
						A[idx++] = 0;
					else
						A[idx++] = 1;
				}
			}
		}
		cin >> Qu;//cantidad de preguntas 
		char s;
		ll l, r;
		build(1, 0, idx - 1);
		ll ask = 0;
		for(ll j = 0; j < Qu; j++){//accion segun el query
			cin >> s;
			cin >> l >> r;
			if(s == 'S'){//contar cantidad de bucaneros (suma de rango en el arbol)
				cout <<"Q"<<++ask<<": "<< Q(1, 0, idx - 1, l , r) <<endl;
			}
            // las siguentes 3 lineas actualizan el arbol segun el query 
			if(s == 'E'){ // transforma a barbaricos 
				U(1, 0, idx - 1, l, r, 'E');
			}
			if(s == 'F'){//transforma a bucaneros
				U(1, 0, idx - 1, l, r, 'F');
			}
			if(s == 'I'){//invierte los piratas 
				U(1, 0, idx - 1, l, r, 'I');
			}
		}	
	}
	return 0;
}


/*
Tarea No.1
Ejercicio No.1
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: https://gist.github.com/jairsaidds/adebe737b804c41fdc1046e2eaca023f
*/