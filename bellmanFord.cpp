// Bellman Ford Algorithm

#include <bits/stdc++.h>
using namespace std;

#define v 4
#define INF 9999

void bellmanFord(int graph[][v]){
	int dist[v][v];
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			dist[i][j]=graph[i][j];

	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}

	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++) cout<<dist[i][j]<<"  ";
		cout<<endl;
	}
}

int main(){
	int graph[v][v] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
	bellmanFord(graph);
	return 0;
}