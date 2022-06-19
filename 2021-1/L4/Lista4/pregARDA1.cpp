#include <iostream>

using namespace std;

int main()
{
	//freopen("maps.txt","r",stdin);
	int o = 1;
	while(o--){
		int M1,M2,N1,N2;//escaneo de datos
		cin>>M1>>M2;
		char gollum[M1][M2];
		for (int i = 0; i < M1; ++i){
			for (int j = 0; j < M2; ++j){
				cin>>gollum[i][j];
			}
		}
		cin>>N1>>N2;
		char aragorn[N1][N2];
		for (int i = 0; i < N1; ++i){
			for (int j = 0; j < N2; ++j){
				cin>>aragorn[i][j];
			}				
		}
		int c = 0;
		for (int i = 0; i <= N1-M1; ++i)//analisis de caso para todos los espacios del mapa
		{
			for (int j = 0; j <= N2-M2; ++j)
			{
				bool found = true;
				for (int k = 0; k < M1; ++k)
				{
					for (int l = 0; l < M2; ++l)
					{
						//printf("(%d,%d):%c vs (%d,%d):%c \n", l,k,gollum[k][l],j+l,i+k,aragorn[i + k][j + l]);
						if(gollum[k][l] != aragorn[i + k][j + l]){//si se encuentra una discrepancia entre los mapas, se cuenta como fallida la busqueda 
							found = false;
							break;
						}

					}
					if(!found)break;
				}
				if(found){
					c++;
					printf("(%d,%d)\n",i+1,j+1);
				}
			}
			
		}
		if(c==0)printf("NO MATCH FOUND...\n");

		
		
	}
	return 0;
}

/*
Ejercicio No.2
Tarea No.4
SPOJ nick: @nisp_2
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia.
obs: Despues de mucho pelear con rabin-karp, no logre encontrar el error de mi codigo por lo que opte por una solucion de fuerza bruta :c
*/