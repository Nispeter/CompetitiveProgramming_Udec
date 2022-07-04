#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long>
typedef long long ll;
const int N=205;
struct point{
	int x,y;
	point(){}
	point(int _x,int _y){x=_x,y=_y;}
	point operator - (const point & b) const {
		return point(x-b.x,y-b.y);
	}
};
pll add(pll a,pll b){
	return {a.first+b.first,a.second+b.second};
}
ll cross(point a,point b){
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
point a[N];
pll f[N][N]; //dp de contador , area
int n,K;
bool check(ll x) { //binary search x prediccion de respuesta
	for(int len=3;len<=n;++len)
		for(int l=1;l+len-1<=n;++l){ //l<=n-len+1: Numero de diagonales que pueden ser dibujadas desde un punto
			int r=l+len-1; // el punto donde las diagonales se distancian mientras len incrementa 
			f[l][r]={0,0}; //f[l][r]: dp para los subpolignonos al recorrer r
			for(int k=l+1;k<r;++k){
				pll c=add(f[l][k],f[k][r]); //l~k, k~r
				c.second+=cross(a[k]-a[l],a[r]-a[l]); //c.second: nueva area
				if(c.second>=x) c.second=0,c.first++; //si el ancho es mayor -> se suma c.first, calculado como f[l][r].second value x
				f[l][r]=max(f[l][r],c); 
			}							
		}								
  return f[1][n].first >= K; //Numero de divisiones por intervalo mayores que x
}
signed main(){
	cin>>n>>K;++K; //vertices y cortes 
	for(int i=1;i<=n;++i)
		cin>>a[i].x>>a[i].y;//escaneo de datos
	ll l=0,r=1e18; 
    //bs del valor inicial, se setea el rango desde l a r y se checkea si la respuesta es correcta iterando
	while(l<r){ //se hace bs para encontrar la respuesta l
		ll mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
}

/*
Tarea No.4
Ejercicio No.4
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria: https://codeforces.com/problemset/submission/1572/129963665
*/