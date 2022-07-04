#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ld  long double
 
const int INF = 1e9 + 7;
 
class maxflow{
public:
    int N;
    vector<vector<int>> adj;
    vector<vector<int>> capacity;
    vector<bool> visited;
    maxflow(int _N){
        N = _N;
        adj.resize(N + 1);
        visited.resize(N + 1);
        capacity = vector<vector<int>> (N + 1 , vector<int>(N + 1 , 0));
    }
 
    void addEdge(int u , int v , int cap){
        adj[u].push_back(v);
        capacity[u][v] = cap;
    }
 
    int breadth_first_search(int source , int sink , vector<int> &parents){ //bfs para edmonds karp
        fill(parents.begin(), parents.end() , -1);
        parents[source] = -2;
        queue<pair<int , int>> que;
        que.push({source , INF});
 
        while(!que.empty()){
            int current = que.front().first;
            int flow = que.front().second;
            que.pop();
            for(auto child : adj[current]){
                if(parents[child] != -1) continue;
                if(capacity[current][child] == 0) continue;
                int flowhere = min(flow , capacity[current][child]);
                parents[child] = current;
                if(child == sink) {
                    return flowhere;
                }
                que.push({child , flowhere});
            }
        }
        return 0;
    }
 
    int ek(int source,  int sink){ //flujo maximo metodo de resolucion edmond karp
        int flow = 0;
 
        vector<int> parents(N + 1);
 
        int augmentingflow = 0;
        while((augmentingflow = breadth_first_search(source, sink, parents))){
            flow += augmentingflow;
            int current = sink;
            while(current != source){
                int previous = parents[current];
                capacity[previous][current] -= augmentingflow;
                capacity[current][previous] += augmentingflow;
                current = previous;
            }
        }
        return flow;
    }
 
    void dfs(int source){
        visited[source] = 1;
        cout << source << " ";
        for(auto child : adj[source]){
            if(visited[child] == 1) continue;
            dfs(child);
        }
    }
 
    void dbggraph(){
        cout << "the edges in the graph " << endl;
        for(int i = 1; i <= N; i++){
            cout << "vertex " << i << " --> ";
            for(auto child : adj[i]){
                cout << child  << " ";
            }
            cout << endl;
        }
        cout << "the capacities " << endl;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cout << capacity[i][j] << " ";
            }
            cout << endl;
        }
    }
};
 
set<int> primes;
 
void factorize(int a){ //factorizacion en base a primos 
    int temp = a;
    for(int j = 2; 1ll * j * j <= a; j++){
        if(temp % j == 0){
            while(temp % j == 0){
                temp /= j;
            }
            primes.insert(j);
        }
    }
    if(temp != 1) primes.insert(temp);
}
 
int getcount(int num , int pr){
    int counter = 0;
    while(num % pr == 0){
        counter++; 
        num /= pr;
    }
    return counter;
}
void solve(){
    int N , M; //tamaño del arreglo y cantidad de good pairs 
    cin >> N >> M;
 
    vector<int> a(N + 1);
 
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        factorize(a[i]);
    }
 
    vector<pair<int , int>> edges;
    for(int i = 1; i <= M; i++){
        int u , v; cin >> u >> v;
        edges.push_back({u , v});
    }
    
    int ans = 0;
    for(auto pr : primes){
        int vertices = 1;
        vector<vector<int>> vertexgroups(N + 1);
        for(int i = 1; i <= N; i++){//cada factor primo tendra su grupo de vertices 
            int count = getcount(a[i], pr);
            for(int j = 0; j < count; j++){
                vertices++;
                vertexgroups[i].push_back(vertices);
            }
        }
        int source = 1;
        vertices++;
        int sink = vertices;
        maxflow maxflow(vertices + 4);
        for(int i = 1; i <= M; i++){//se crean aristas entre nodos solo si hay una buena suma entre ellos 
            int first = edges[i - 1].first;
            int second = edges[i - 1].second;
            if(first % 2 == 0) swap(first , second);
            assert(first % 2 == 1);//implica que el grupo se puede dividir por el ptrimo
            for(auto firstver : vertexgroups[first]){
                for(auto secondver : vertexgroups[second]){
                    maxflow.addEdge(firstver, secondver, 1);
                    maxflow.addEdge(secondver, firstver , 0);
                }
            }
            for(auto firstver : vertexgroups[first]){
                maxflow.addEdge(source , firstver , 1);
                maxflow.addEdge(firstver , source , 0);
            }
 
            for(auto secondver : vertexgroups[second]){
                maxflow.addEdge(secondver , sink , 1);
                maxflow.addEdge(sink , secondver , 0);
            }
        }//grafo resultante bipartito 
        int flow = maxflow.ek(source, sink); //se obtienen el flujo maximo 
        ans += flow;
    }
    cout << ans << endl;
}
 
int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr);                       
    cout.tie(nullptr);
    int tt = 1;
    
    for(int tc = 1; tc <= tt; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
}

/*
Tarea No.5
Ejercicio No.3
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria:https://codeforces.com/contest/498/submission/104527559
*/