#include<bits/stdc++.h>

using namespace std;

int adj[100000];//matriz que almacena la adyacencia con direccion de cada nodo
vector<int>sum;//vector de alcance de cada nodo
bool visited[100000];//arreglo que almacena si se ha visitado un nodo o no
int cnt=0;


int dfs(int s)//depth first search
{
    visited[s]=true;//cambia 
        int x=adj[s];//
        if(!visited[x])//si no se ha visitado un nodo adyacente se hace dfs denuevo
        {
            cnt++;//se agrega uno al contador 
            dfs(x);
        }
    visited[s]=false;
    return sum[s]=cnt;//retorna la cantidad de nodos de alcance de forma recursiva

}

int main()
{
	//freopen("emails.txt","r",stdin);
    int n,m,i,j,t,u,v,a,mx=0,ans;
    /*
    n:numero de marcianos en cada comunidad
    i;iterador
    j:iterador
    t:cantidad de casos a testear (comunidades)
    u:marciano que envia el email (auxiliar)
    v:marciano que recive el email (auxiliar)
    a:variable auxiliar que almacena la cantidad de marcianos en cada comunidad
    mx:alcance maximo de emails siguendo la secuencia de envios desde un nodo especifico
    */
    cin>>t;

    for(j=1; j<=t; j++)//por cada caso
    {
        cin>>n;
        a=n;

        while(a--)//se escanea la lista de adyacencias 
        {
            cin>>u>>v;
            adj[u]=v;//se establece la adyacencia de cada nodo
        }
        sum.assign(n+1,-1);//se reasignan los valores del vector sum como -1 (no visitado o con valor de recorrido nulo)
        cnt=1;//establece el contador
        mx=0;//establece la cantidad maxima 
        for(i=1;i<=n;i++){
            if(sum[i]==-1){//si el nodo no ha sido visitado 
               dfs(i);//se busca en profundidad
               sum[i]=cnt;//y se establece que el recorrido de ese nodo ya ha sido analizado
            }
            if(cnt>mx){//se establece el mayor alcance entre los nodos
                mx=cnt;
                ans=i;
            }
            cnt=1;
        }
        cout<<"Case "<<j<<": "<<ans<<endl;//impresion del nodo con mayor valor
    }

}

/*
Ejercicio No.7
Lista No.3
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: https://mysolutions4you.wordpress.com/2018/10/25/uva-12442forwarding-emails-solution/
*/