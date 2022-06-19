#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

#define tipo double
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
const tipo EPS = 1e-9;
const tipo INF = 1e14;
#define N 502 

//Dado un grafo bipartito completo con costos no negativos, encuentra el matching perfecto de minimo costo.
tipo cost[N][N], lx[N], ly[N], slack[N]; //llenar: cost=matriz de adyacencia
int n, max_match, xy[N], yx[N], slackx[N],prev2[N];//n=cantidad de nodos
bool S[N], T[N]; //sets S and T in algorithm
void add_to_tree(int x, int prevx) {
	S[x] = true, prev2[x] = prevx; 
	forn(y, n) if (lx[x] + ly[y] - cost[x][y] < slack[y] - EPS)
		slack[y] = lx[x] + ly[y] - cost[x][y], slackx[y] = x;
}
void update_labels(){
	tipo delta = INF; 
	forn (y, n) if (!T[y]) delta = min(delta, slack[y]);
	forn (x, n) if (S[x]) lx[x] -= delta;
	forn (y, n) if (T[y]) ly[y] += delta; else slack[y] -= delta;
}
void init_labels(){
	zero(lx), zero(ly);
	forn (x,n) forn(y,n) lx[x] = max(lx[x], cost[x][y]);
}
void augment() {
	if (max_match == n) return; 
	int x, y, root, q[N], wr = 0, rd = 0; 
	memset(S, false, sizeof(S)), memset(T, false, sizeof(T)); 
	memset(prev2, -1, sizeof(prev2)); 
	forn (x, n) if (xy[x] == -1){
		q[wr++] = root = x, prev2[x] = -2;
		S[x] = true; break; }
	forn (y, n) slack[y] = lx[root] + ly[y] - cost[root][y], slackx[y] = root;
	while (true){
		while (rd < wr){
			x = q[rd++];
			for (y = 0; y < n; y++) if (cost[x][y] == lx[x] + ly[y] && !T[y]){
				if (yx[y] == -1) break; T[y] = true; 
				q[wr++] = yx[y], add_to_tree(yx[y], x); }
			if (y < n) break; }
		if (y < n) break; 
		update_labels(), wr = rd = 0; 
		for (y = 0; y < n; y++) if (!T[y] && slack[y] == 0){
			if (yx[y] == -1){x = slackx[y]; break;}
			else{
				T[y] = true; 
				if (!S[yx[y]]) q[wr++] = yx[y], add_to_tree(yx[y], slackx[y]);
			}}
		if (y < n) break; }
	if (y < n){
		max_match++; 
		for (int cx = x, cy = y, ty; cx != -2; cx = prev2[cx], cy = ty)
			ty = xy[cx], yx[cy] = cx, xy[cx] = cy;
		augment(); }
}
tipo hungarian(){
	tipo ret = 0; max_match = 0, memset(xy, -1, sizeof(xy)); 
	memset(yx, -1, sizeof(yx)), init_labels(), augment(); //steps 1-3
	forn (x,n) ret += cost[x][xy[x]]; return ret;
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
	    for(int i = 0;  i<N ; i++)
	        for(int j = 0;  j<N ; j++)
	         cost[i][j] = 0;
	    int b;
	    cin>>n>>b; 
	    int cant = n/6;
	    for (int i = 0; i < b; i++){
	        string a1,a2;
	        cin>>a1>>a2;
	        if(a1 == "XS" || a2 == "XS"){
	            for (int j = 0; j < cant; j++)
	                cost[i][j] = 1;
	        }
	        if(a1 == "S" || a2 == "S"){
	            for (int j = 0; j < cant; j++)
	                cost[i][j+cant] = 1;
	        }
	        if(a1 == "M" || a2 == "M"){
	            for (int j = 0; j < cant; j++)
	                cost[i][j+2*cant] = 1;
	        }
	        if(a1 == "L" || a2 == "L"){
	            for (int j = 0; j < cant; j++)
	                cost[i][j+3*cant] = 1;
	        }
	        if(a1 == "XL" || a2 == "XL"){
	            for (int j = 0; j < cant; j++)
	                cost[i][j+4*cant] = 1;
	        }
	        if(a1 == "XXL" || a2 == "XXL"){
	            for (int j = 0; j < cant; j++)
	                cost[i][j+5*cant] = 1;
	        }
	            
	        
	    }
	    //n = 6;
	    //int b = 4;
	    
	    /*int aux[18][18] = {
    	    {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    	    {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    	};*/
    	
    	/*int aux[6][6] = {
    	    {0,1,0,0,1,0},
    	    {0,1,0,1,0,0},
    	    {0,0,0,1,1,0},
    	    {0,0,0,1,1,0},
    	    {0,0,0,0,0,0},
    	    {0,0,0,0,0,0}
    	};*/
    	
    	
    	
    	/*for(int i = 0; i < n; i++){
    	    for(int j = 0;j < n; j++){
    	cout << cost[i][j] << " ";
    	}
    	cout << endl;
    	}*/
        
        if(hungarian() != b)
             cout<<"NO";
        else 
            cout<<"YES";
        cout<<endl;
    	//cout << hungarian() << endl;
    
    	//for(int i = 0; i < n; i++)cout << xy[i] << " ";
    	//cout << endl;
    	/*for(int i = 0; i < n; i++)cout << yx[i] << " ";
    	cout << endl;*/
	
	}
	
	

	return 0;
}

/*
Ejercicio No.3
Tarea No.4
UVA id: Nisp
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria:Solucion propia.
hungarian algorithm: rescatado de clases practicas
*/






