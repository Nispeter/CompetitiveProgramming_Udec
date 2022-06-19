#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("blocks.txt","r",stdin);


	int n = 1;

	while(n != 0 ){

		
		cin>>n;
		int order[n];

		while (n != 0){

			stack<int> line;

			cin>>order[0];
			if(order[0]==0)break;

			for (int i = 1; i < n; ++i)cin>>order[i];

			bool valid = true;
            int cont = 1;
            

            for(int i = 0; i < n; i++){
            	for (cont ; cont <= n; ++cont)
            	{
            		if(cont <= n and (line.empty() or line.top() != order[i])){
            			line.push(cont);
            		}
            		else break;
            		
            	}
                if(order[i] == line.top()){
                    line.pop();
                }else{
                    valid = false;
                    break;
                }

            }

			if(valid)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;

		}

		if(order[0]==0)printf("\n");
		
		
	}
	return 0;
}




/*
Ejercicio No.1
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/