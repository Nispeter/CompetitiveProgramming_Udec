#include<bits/stdc++.h>
using namespace std;

set<int>pep[101];
int p[101],r[101];

void reset(int n)
{
    for(int i=1;i<=n;i++)
    {
        pep[i].clear();
        p[i] = i;
        r[101] = 1;
    }
}

int Find(int a)//para encontrar el parent de un nodo
{
    return (a==p[a]) ?  a : p[a] = Find(p[a]);
}

bool make_union(int a,int b)//union entre nodos de un conjunto 
{
    int u = Find(a);//se  encentran los pares de los nodos a unir 
    int v = Find(b);

    if(u==v)    return false;

    if(r[u]>=r[v])// se redefinen los parents de cada uno en relacion a cual sea mayor
    {
        r[u]+=r[v];
        p[v] = u;
    }
    else
    {
        r[v]+=r[u];
        p[u] = v;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char buf[100];
    int test,P,T,u,v;

    scanf("%d\n\n",&test);//test cases

    while(test--)
    {
        gets(buf);

        sscanf(buf,"%d %d",&P,&T);//escaneo de datos
        reset(P);
        while(gets(buf))
        {
            if(!buf[0]) break; //escanea p y t hasta encontrar un enter  
            sscanf(buf,"%d %d",&u,&v);
            pep[u].insert(v);//set para aislar los nodos sin repeticiones 
        }

        int ans = P;//cantidad de opiniones 
        for(int i=1;i<=P;i++)
            for(int j=i+1;j<=P;j++)
                if(pep[i]==pep[j]&&make_union(i,j))//si ya se encontro anteriormente esta opinion, se descuenta del total 
                    ans--;

        printf("%d\n",ans);//impresion de distintas opiniones 
        if(test)    puts("");//se imprime un enter al final
    }
    return 0;
}

/*
Tarea No.2
Ejercicio No.4
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: https://github.com/notorious94/UVa-solution/blob/master/10227%20UVA.cpp
*/
