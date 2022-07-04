#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in1.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int a[n];
		int m = INT_MIN;
		int max_value = INT_MAX-100000000;
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
			if(a[i] > m)
				m =a[i];
		}
		int space = 2*m+1;
		
		vector<vector<int>> dp(n+1);	
		for (int i = 0; i < n+1; i++)
		{
			dp[i] = vector<int>(space,max_value);
		}
		dp[0][0] = 0;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < space ; j++)
			{
				if(dp[i][j] != max_value){
					int np = i + 1;
					int va = a[i];
					int mp = max(j-va,0);
					int rec = min(dp[np][mp],dp[i][j]+va);
					dp[np][mp] = rec;
					
					if(j+va < dp[np].size()){
						int ma = max(dp[i][j] - va , 0);
						rec = min(dp[np][j+va], ma);
						dp[np][j+va] = rec;
					}
				}
			}
			
		}
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < space ; j++)
		// 	{
		// 		printf("%d ",dp[i][j]);
		// 	}
		// 	cout<<endl;
		// }

		int range = space;
		for (int i = 0; i < space ; i++)
		{	
			int act = i + dp[n][i];
			//cout<<"act"<<range<<endl;
			if(range > act)
				range = act;
		}
		printf("%d\n",range);
		
	}

	return 0;
}

/*
Tarea No.4
Ejercicio No.1
Online Judge ID: nispeter2
Autor: Nicolas Parra Garcia.
Autoria: Solucion propia
*/