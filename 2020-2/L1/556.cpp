#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	int b=1,w=1;
    here:
    while(b!=0&&w!=0)
    {
        cin>>b>>w;
        if(b==0&&w==0)goto here;
        char aux;
        int maze[b+2][w+2];
        for (int i = 1; i < b+1; ++i)
        {
            for (int j = 1; j < w+1; ++j)
            {
                cin>>aux;//escaneo del mapa
                if(aux=='0')maze[i][j]=0;
                else maze[i][j]=-1;
            }
        }
        //transformacion conveniente del mapa
        for (int i = 0; i < b+2; ++i)
        {
            maze[i][0]=-1;
            maze[i][w+1]=-1;
        }

        for (int i = 0; i < w+2; ++i)
        {
            maze[0][i]=-1;
            maze[b+1][i]=-1;
        }

        int i = b, j = 1;
        char direction = 'r';

        while(maze[b][1]!=2){//posibles direcciones del robot, siempre favoreciendo el lado derecho y dependiendo de su movimiento anterior
            ++maze[i][j];//se le suma uno a la posicion por donde paso el robot
            switch (direction){
                case 'r':
                    if(maze[i+1][j]!=-1){
                        ++i;
                        direction = 'd';
                        break;
                    }
                    else if(maze[i][j+1]!=-1){
                        j++;
                        direction = 'r';
                        break;
                    }
                    else if(maze[i-1][j]!=-1){
                        --i;
                        direction = 'u';
                        break;
                    }
                    else if(maze[i][j-1]!=-1){
                        --j;
                        direction = 'l';
                        break;
                    }
                    break;

                case 'u':
                    if(maze[i][j+1]!=-1){
                        j++;
                        direction = 'r';
                        break;
                    }
                    else if(maze[i-1][j]!=-1){
                        --i;
                        direction = 'u';
                        break;
                    }
                    else if(maze[i][j-1]!=-1){
                        --j;
                        direction = 'l';
                        break;
                    }
                    else if(maze[i+1][j]!=-1){
                        ++i;
                        direction = 'd';
                        break;
                    }
                    break;

                case 'l':
                    if(maze[i-1][j]!=-1){
                        --i;
                        direction = 'u';
                        break;
                    }
                    else if(maze[i][j-1]!=-1){
                        --j;
                        direction = 'l';
                        break;
                    }
                    else if(maze[i+1][j]!=-1){
                        ++i;
                        direction = 'd';
                        break;
                    }
                    else if(maze[i][j+1]!=-1){
                        j++;
                        direction = 'r';
                        break;
                    }
                    break;

                case 'd':
                    if(maze[i][j-1]!=-1){
                        --j;
                        direction = 'l';
                        break;
                    }
                    else if(maze[i+1][j]!=-1){
                        ++i;
                        direction = 'd';
                        break;
                    }
                    else if(maze[i][j+1]!=-1){
                        j++;
                        direction = 'r';
                        break;
                    }
                    else if(maze[i-1][j]!=-1){
                        --i;
                        direction = 'u';
                        break;
                    }
                    break;
            }
        }
        int cont[]={0,1,-1,0,0};
        for (int i = 1; i < b+1; ++i)//se cuenta las repeticiones de los bloques 
        {
            for (int j = 1; j < w+1; ++j)
            {
                switch(maze[i][j]){
                    case 0:
                        ++cont[0];
                        break;
                    case 1:
                        ++cont[1];
                        break;
                    case 2:
                        ++cont[2];
                        break;
                    case 3:
                        ++cont[3];
                        break;
                    case 4:
                        ++cont[4];
                        break;
                }
            }
        }
        for (int i = 0; i < 5; ++i)
        {
            printf("%3d",cont[i] );
        }
        cout<<endl;
    }

	
	return 0;
}
/*
Ejercicio No.6
Tarea No.1
Online Judge ID: 1171308
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
*/