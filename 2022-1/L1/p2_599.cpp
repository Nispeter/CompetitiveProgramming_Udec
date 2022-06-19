#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class DisjSet {
	int *rank, *parent, n;
    map<int,int> m;

public:
	// Constructor to create and
	// initialize sets of n items
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	// Creates n single item sets
	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	// Finds set of given item x
	int find(int x)
	{
		// Finds the representative of the set
		// that x is an element of
		
		if (parent[x] != x) {
				//cerr<<"a"<<endl;
			// if x is not the parent of itself
			// Then x is not the representative of
			// his set,
			parent[x] = find(parent[x]);

			// so we recursively call Find on its parent
			// and move i's node directly under the
			// representative of this set
		}
       if (parent[x] == x) m[parent[x]]++;
		return parent[x];
	}

	// Do union of two sets represented
	// by x and y.
	void Union(int x, int y)
	{
		// Find current sets of x and y
		int xset = find(x);
		int yset = find(y);

		// If they are already in same set
		if (xset == yset){
            
			return;
        }
		// Put smaller ranked item under
		// bigger ranked item if ranks are
		// different
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}

		// If ranks are same, then increment
		// rank.
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}

    void printParents(){
        for (int i = 0; i < sizeof(parent)/sizeof(*parent); i++)
        {
            printf("%d\n",m[parent[i]]);
        }
        
    }

    void printRank(){
        for (int i = 0; i < sizeof(rank)/sizeof(*rank); i++)
        {
            printf("%d\n",rank[i]);
        }
        
    }
};

int main()
{

    //freopen("p2.txt","r",stdin);
    int N;
    cin>>N;
    while(N--){

        string s;
        vector<pair<int,int>>p;
        set<char>c;

        while(cin>>s){
            if(s[0] == '*')
                break;
            else {
                auto aux = pair<int,int>((int)s[1] - 'A',(int)s[3] - 'A');
                p.push_back(aux);
            }
        }

        cin>>s;
        int n = (int)p.size();
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] != ',')
                c.insert(s[i]);
        }
        

        DisjSet obj(26);
        for (int i = 0; i < n; i++)
        {
            //cerr<<"flag"<<i+1<<" p[i]1&2: "<<p[i].first<<","<<p[i].second<<endl;
            obj.Union(p[i].first,p[i].second);
            //cerr<<"flag2"<<endl;
        }
    
        map<int,int> cont;
        
        set<char>::iterator it = c.begin();
        int acorn = 0,tree = 0;
        while(it != c.end()){
			//cerr<<obj.find(*it - 'A')<<endl;
            cont[obj.find(*it - 'A')]++;
            it++;
        }
		map<int,int>::iterator itr = cont.begin();
        while(itr != cont.end()){
            if(itr->second == 1 )
                acorn++;
            else tree++;
            itr++;
        }
		printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
    }
    
	return 0;
}


/*
Tarea No.2
Ejercicio No.2
Online Judge ID: Nisp
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
Algoritmo disjoint set rescatado de: https://www.geeksforgeeks.org/disjoint-set-data-structures/
*/
