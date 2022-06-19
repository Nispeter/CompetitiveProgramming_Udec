#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char vocals[5] = {'a','e','i','o','u'};
    string s = "hola que pasa comoestamos";
    cin>>s;

    int cont = 0;
    int pos = s.size() - 1;
    int max = 20;
    while(max > 0){

        if (pos == 0)
            break;
        max --;
        bool aux = false;
        cerr<<"pos: "<<pos<<endl;
        for (int i = 0; i < 5; i++)
        {   
            if(s[pos] == vocals[i]){
                cerr<<"s[pos]: "<<s[pos]<<", vocal[i]: "<<vocals[i]<<endl;
                if(pos > 0)
                    s = s.substr(0,pos);
                else 
                    s = s[pos];
                cerr<<"substring: "<<s<<endl;
                reverse(s.begin(),s.end());
                cerr<<"reversed: "<<s<<endl;
                pos = s.size()-1;
                aux = true;
                break;
            }
        }
        if(s.size() == 1)
                cont++;
                break;
        if(aux){
            cont = 1;
        }  
        else {
            pos--;
            cont++;
        }
    }
    cout<<cont;

    // s = s.substr(0,4);
    // cerr<<s<<endl;
    // cerr<<s.size()<<endl;

    return 0;
}
