
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int t, b, ng, nb;
multiset<int> green, blue;//almacen para fuerza individual de lemmings azules y verdes (en orden ascendiente)
int main() {
    cin >> t;//escaneo de numero de casos
    for(int tt=0; tt<t; tt++) {
	if(tt > 0) cout << '\n';
	green.clear();
	blue.clear();//limpieza de los multiset
	cin >> b >> ng >> nb;//escaneo de numero de campos de batalla,cantidad de  lemmings verdes y azules,
	for(int i=0; i<ng; i++) {
	    int x;
	    cin >> x;//escaneo de numero de las fuerzas de cada lemming verde
	    green.insert(x);
	}
	for(int i=0; i<nb; i++) {
	    int x;
	    cin >> x;//escaneo de numero de las fuerzas de cada lemming azul
	    blue.insert(x);
	}
	while(!green.empty() && !blue.empty()) {
	    vector<int> gw, bw;//vectores auxiliares que contienen los lemmings que pelearan en cada ronda
	    int fights = min(b, (int)min(green.size(), blue.size()));//cantidad de batallas definidas por el menor entre la cantidad dada y el color que tenga menos lemmings 
	    for(int i=0; i<fights; i++) {
			auto tg = green.end(), tb = blue.end(); tg--; tb--;//cantidad de lemmings restantes en cada equipo
			int gs = *tg, bs = *tb;//fuerza respectiva del lemming seleccionado
			green.erase(tg); blue.erase(tb);
			if(gs > bs) {//balance de fuerzas
			    gw.push_back(gs-bs);//si el verde gana la batalla es agregado al vector auxliar
			} else if(bs > gs) {
			    bw.push_back(bs-gs);//si el azul gana la batalla es agregado al vector auxliar
			}
	    }
	    for(auto i : gw) green.insert(i);//los lemmings sobrevivientes de esta ronda son agregados de vuelta a las filas (multiset)
	    for(auto i : bw) blue.insert(i);
	}
	if(green.empty() && !blue.empty()) {//si el set azul tiene valores significa que los azules ganaron
	    cout << "blue wins\n";
	    for(multiset<int>::reverse_iterator it=blue.rbegin(); it!=blue.rend(); it++)
		cout << *it << '\n';
	} else if(!green.empty() && blue.empty()) {//si el set verde tiene valores significa que los verdes ganaron
	    cout << "green wins\n";
	    for(multiset<int>::reverse_iterator it=green.rbegin(); it!=green.rend(); it++)
		cout << *it << '\n';
	} else cout << "green and blue died\n";//si no hay lemmings sobrevivientes
    }
}

/*
Ejercicio No.4
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://www.davidudelson.com/blog/2015/07/23/uva-978-lemmings-battle/
*/
