#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

LL substr_count(int n,char *s)
{
    // construccion del SA
    VI cnt(128);
    for(int i=0;i<n;i++)
        cnt[s[i]]++;
    for(int i=1;i<128;i++)
        cnt[i]+=cnt[i-1];
    VI p(n);
    for(int i=0;i<n;i++)
        p[--cnt[s[i]]]=i;
    VVI c(1,VI(n));
    int w=0;
    for(int i=0;i<n;i++)
    {
        if(i==0 || s[p[i]]!=s[p[i-1]]) w++;
        c[0][p[i]] = w-1;
    }

    for(int k=0,h=1;h<n;k++,h*=2)
    {
        VI pn(n);
        for(int i=0;i<n;i++) {
            pn[i] = p[i] - h;
            if(pn[i]<0) pn[i] += n;
        }
        VI cnt(w,0);
        for(int i=0;i<n;i++)
            cnt[c[k][pn[i]]]++;
        for(int i=1;i<w;i++)
            cnt[i]+=cnt[i-1];
        for(int i=n;i--;)
            p[--cnt[c[k][pn[i]]]]=pn[i];
        w=0;
        c.push_back(VI(n));
        for(int i=0;i<n;i++)
        {
            if(i==0 || c[k][p[i]] != c[k][p[i-1]]) {
                w++; 
            } else {
                int i1 = p[i]   + h; if(i1>=n) i1-=n;
                int i2 = p[i-1] + h; if(i2>=n) i2-=n;
                if(c[k][i1]!=c[k][i2]) w++;
            }
            c[k+1][p[i]] = w-1;
        }
    }

    //return son todos los substrings - lcp de sus vecinos
    LL ans = LL(n)*(n-1)/2;
    for(int k=1;k<n;k++)
    {
        // calculo de lcp de sufijos vecinos 
        int i=p[k];
        int j=p[k-1];
        int cur = 0;
        for (int h=c.size(); h--;)
            if (c[h][i] == c[h][j]) {
                cur += 1<<h;
                i += 1<<h;
                j += 1<<h;
            }
        ans-=cur;
    }
    return ans;
}

char s[200003];

int main()
{
    scanf("%s",s);//scaneo de string
    int n = strlen(s)+1;
    s[n-1] = 'a'-1; // caracter de termino

    scanf("%s",s+n);
    int m = strlen(s+n)+1;
    s[n+m-1] = 'a'-2; //segundo caracter de termino
    s[n+m]=0;

    LL ans1 = substr_count(n,s);//cantidad de substrings de string 1
    LL ans2 = substr_count(m,s+n);//cantidad de substrings de string 2
    LL ans3 = substr_count(n+m,s)-LL(n)*m; // cantidad de substrings de la interseccion entre ambos strings 
    LL ans = 2*ans3-ans1-ans2; // substr_count(str1) + susbstr_count(str2) - susbtrcount(str1 inter str2)
    printf("%lld\n",ans);
    return 0;
}
/*
Ejercicio No.8
Tarea No.4
SPOJ nick: @nisp_2
Autor: Nicolas Parra Garcia.
Autoria: www.codechef.com/download/Solutions/COOK32/Tester/TASTR.cpp
*/

