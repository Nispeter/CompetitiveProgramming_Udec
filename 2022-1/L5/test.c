//Realizado de manera individual
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){	
	char cad[1001];
	int num1=0,num2=0,esp,n1=0,n2=0,menor;	
	
	printf("Ingresar 2xN1 3xN2\n");
	printf("Con N1 y N2 dos numeros enteros:\t");
	scanf("%[^\n]",cad);
		
	int tamcad=strlen(cad),i,esps=0;	
	
	for(i=0; i<tamcad;i++){
		if(cad[i]==32){
			esp=i;
			esps++;
		}	
	}

	for(i=0;i<esp-2;i++){
		int ind=esp-1-i; 
		if(cad[ind]>=48 && cad[ind]<=58){
			num1 +=(cad[ind]-48)*pow(10,i);
			n1++;
		}
	}
	
	for(i=0;i<tamcad-esp-2;i++){
		int ind=tamcad-i-1;
		if(cad[ind] >= 48 && cad[ind]<=58){
			num2+=(cad[ind] -48)*pow(10, i);
			n2++;
		}
	}	
	while(cad[0]!=50 || cad[1]!='x' || esps!=1 || cad[esp+1]!=51 || cad[esp+2]!='x' || n1==0 || cad[esp+2]=='\0' || n2 ==0){		
		return 0;
	}
		
	int inds1=2;
	int inds2=esp+3;
	
	if(cad[inds1]==45){
		num1=-num1;
	}if(cad[inds2]==45){
		num2=-num2;
	}if(num1<num2){
		menor=num1;
	}else{
		menor=num2;
	}
		
	printf("%d", menor);	
	return(0);
}