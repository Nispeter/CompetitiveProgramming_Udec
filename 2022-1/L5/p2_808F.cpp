#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std ;
 const int N = 10000 ;
 const int inf = 0x3f3f3f3f ;
 int h[N],num = 1 ,k;
 int P[N],T[N],L[N];
 int prime[ 1500 ],ptot,n,sum,all,pos,dis[N],s,t,cur[N];
 inline char nc( ){
     static char buf[ 100000 ],*p1=buf,*p2=buf;
     return p1==p2&&(p2=(p1=buf)+fread(buf, 1 ,100000 ,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
     register int x = 0 ,f = 1 ;
     register char ch=nc();
     while (ch< '0' ||ch> '9' ){ if (ch== '-' )f *=- 1 ;ch=nc();}
     while (ch>= '0' &&ch<= '9' )x=(x<< 3 )+(x<< 1 )+ch- '0' ,ch =nc();
     return f*x;
}
struct Edge{
     int v,next,c,pr;
};
Edge e[ 100 *N]; //estructura base del grafo 
 void adde( int i, int j, int c){
    e[++num].v=j,e[num].next=h[i],e[num].c=e[num].pr=c,h[i]=num;
}
void add( int u, int v, int w){
    adde(u,v,w);
    adde(v,u, 0 );
}
inline bool bfs( int mid, int pos){ //verificacion de contradiccion con suma de primos 
     queue<int> q;
     memset (dis, 0 , sizeof (dis));
    q.push(s);
    dis[s]= 1 ;
     while (!q.empty()){
         int u=q.front();q.pop();
         for ( int i=h[u];i;i=e[i] .next){
             int v=e[i].v;
             if (T[v]== 1 &&v!=pos) continue ;
             if (e[i].c&&!dis[v]&&L[v]<=mid ){
               dis[v]=dis[u]+ 1 ;
               q.push(v);
            }
        }
    }
    return dis[t];
}
int dfs( int u, int a, int mid, int pos){ //dfs que busca el flujo maximo 
     if (u==t||a== 0 ) return a;
     int flow= 0 ,f;
     for ( int i=cur[u];i ;i=cur[u]=e[i].next){
         int v=e[i].v;
         if (T[v]== 1 &&pos!=v) continue ;
         if (L[v]<= mid&&dis[v]==dis[u]+ 1 ){
             int x=min(e[i].c,a);
            f=dfs(v,x,mid,pos);
            e[i].c-=f;
            e[i^ 1 ].c+=f;
            flow+=f;
            a-=f;
            if (a== 0 ) return flow;
        }
    }
    if (!flow)dis[u]=- 1 ;
     return flow;
}
void init(){ //inicializacion del grafo con las contradicciones
    prime[++ptot]= 2 ;
     for ( int i= 3 ;i<= 10000 ;i++){
         int j;
         for (j= 2 ;j*j<=i;j++)
         if (i%j== 0 ) break ;
         if (j*j>i)prime[++ptot]=i;
    }
}
bool isprime( int x){ //verificacion de valor primo
     for ( int i= 1 ;prime[i]*prime[i]<=x;i++)
     if (x%prime[i]== 0 ) return false ;
     return true ;
}
void pre(){
     for ( int i = 1 ;i<=n;i++){
          if (T[i]& 1 )
         for ( int j = 1 ;j<=n;j++){
             if (!(T[ j]& 1 ))
              if (isprime(T[i]+T[j]))add(i,j,inf);
        }
    }
}
bool check( int mid){
    all = 0 ; int maxx = 0 ;
     for ( int i = 1 ;i<=n;i++){
         if (L[i]<=mid&&T[i]!= 1 )all+=P[i];
         if (L [i]<=mid&&T[i]== 1 ){
             if (P[i]>maxx){
                maxx=P[i];
                pos=i;
            }
        }
    }
    all+=maxx;
    int flow= 0 ,ans= 0 ;
     for ( int i= 2 ;i<=num;i++) e[i].c=e[i].pr;
     while (bfs(mid,pos)) { for ( int i=s;i<=t;i++)cur[i]=h[i];flow+=dfs(s,inf,mid,pos);}
     return all-flow>=k;
}
int main(){
    init();
    L[ 0 ]=- 1 ; L[ 1200 ]=- 1 ;
    n=read(),k=read();//escaneo de datos 
    s = 0 ,t = 2 *n + 1 ;
     int st=inf,ed = 0 ;
     for ( int i = 1 ;i<=n;i++){
        P[i]=read(),T[i]=read(),L[i]=read();
        st=min(st,L[i]),ed=max(ed,L[i]);
        if (T[i]& 1 )add(s,i,P[i]);
         else add(i,t,P[i]);
    }
    pre();
    int lf=st,rg=ed,ans=- 1 ;
     while (lf<=rg){
        int mid=(lf+rg)>> 1 ;
        if (check(mid)) ans=mid,rg=mid- 1 ;
        else lf=mid+ 1 ;
    }
    if (ans!=- 1 ){
     while (check(ans- 1 )) ans--;
     printf ( "%d\n" ,ans);
    }
    else printf ( "-1\n" );
     return 0 ;
}
/*
Solucion propuesta en codigo:
Se nesesita dividir el nivel, la suma de el firepower no puede ser menor que k. Por lo que se requiere la solucion optima bajo el nivel actual,
esta es  el set independiente de peso maximo.
Cabe notar que numeros pares + impares pueden dar numeros primos. por lo que se clasifican los pares e impares en 2 categorias  donde un impar y un par se suman y dan un primo
incluso en un caso borde. 
la capacidad inicial es inf por la construccion del flujo.
Se construye un origen y un sumidero virtual, donde el unico impar conectado al origen es el limite del firepower. 
El grafo puede contener contradicciones por que solo se conectan las aristas cuando la suma es prima, es decir, cuando son vertices contrarios.
Los numeros pares van al vertice de encuentro y se conectan a la arista de la capacidad de firepower.
Esto es equivalente a recorrer mientras el flujo maximo es el corte minimo, (se necesita el menor costo para desconectar los lados contrarios por que se requiere que 
no haya una suma de numeros primos), por lo que existe una contradiccion.
Este corte minimo elimina la contradiccion (cortando el lado por donde se sumaria originalmente), es decir para que cumpla con el firepower minimo que limita la perdida,
el valor de las cartas que originalmente eran de menor que el nivel actual de dos puntos menos el costo minimo (perdida) para eliminar las contradicciones del firepower.
Si la ganancia es >= k, la verificacion devuelve true.
*/


/*
Tarea No.5
Ejercicio No.2
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria: https://blog.katastros.com/a?ID=00550-8ac77008-b0c3-44c0-82a8-031862b97077
*/