// counting the paths from i to j in k steps

#include <bits/stdc++.h>
using namespace std;
#define V 4

void calculate(int graph[][V],int src,int dest,int steps){
	
	int dp[V][V][steps+1];
	
	for(int k=0;k<=steps;k++){
		
		for(int i=0;i<V;i++){
			
			for(int j=0;j<V;j++){

				dp[i][j][k]=0;
				
				if(k==0 and i==j)
					dp[i][j][k]=1;
				
				if(k==1 and graph[i][j])
					dp[i][j][k]=1;
				
				else if(k>1){
					for(int l=0;l<V;l++)
						if(graph[i][l]) 
							dp[i][j][k]+=dp[l][j][k-1];
				}
			
			}
		
		}
	
	}
	
	cout<<"Answer is "<<dp[src][dest][steps]<<endl;
}




int main(){
	int graph[V][V]={ {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
	calculate(graph,0,3,2);
	return 0;
}