#include <bits/stdc++.h>

using namespace std;
map<char,int>m;

bool update_back(string &n, int pos){
    if(pos < 0)
        return false;
    if(n[pos] != '0'){
        n[pos] -= 1;
        return false;
    }
    else {
        n[pos] = '9';
        update_back(n,pos-1);
        return true;
    } 
}

void update_front(string &n, int pos){
    int cont = 2;
    int number = 57;
    for (int i = pos; i < n.size(); i++)
    { 

        if(cont > 0){
            cont--;
        }
        else{
            cont = 2;
            number--;
        }
        n[i] = (char)number;
    }

}

int main(int argc, char const *argv[])
{
    //freopen("p3.txt","r",stdin);
    //freopen("p3_out.txt","w",stdout);

    string n;
    while(cin>>n){

        m.clear();

        for (int i = 0; i < n.size(); i++)
        {
            //cerr<<n<<endl;
            //cerr<<"analizando n["<<i<<"] = "<<n[i]<<", cant =  "<<m[n[i]]<<endl;
            if(m[n[i]] < 2)
                m[n[i]]++;
            else {
                update_back(n,i);
                    //cerr<<"b"<<n<<endl;
                    //cerr<<n[i]<<" se repitio mas de 2 veces"<<endl;
                update_front(n,i+1);
                    //cerr<<"f"<<n<<endl;
                
                i = -1;
                m.clear();
            } 
        }
        cout<<stoll(n)<<endl;
    }
   return 0;
} 

