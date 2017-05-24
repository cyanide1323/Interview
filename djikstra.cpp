// djikstra's algorithm

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define v 9

int minDistance(int dist[],bool done[]){
	int node;
	int value = INT_MAX;
	for(int i=0;i<v;i++){
		if(!done[i]){
			if(dist[i]<value){
				value = dist[i];
				node = i;
			}
		}
	}
	return node;
}

void djikstra(int graph[][9],int src){
	
	bool done[v];
	int dist[v];

	for(int i=0;i<v;i++){
		dist[i]=INT_MAX; done[i]=false;
	}

	dist[src]=0;
	
	for(int count=0;count<v;count++){
		int u = minDistance(dist,done);
		done[u]=1;
		for(int i=0;i<v;i++){
			if(graph[u][i] and !done[i] and dist[u]!=INT_MAX)
				dist[i]=min(dist[i],graph[u][i]+dist[u]);
		}
	}
	for(int i=0;i<v;i++)
		cout<<i<<"   "<<dist[i]<<endl;
}

int main(){
	int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	djikstra(graph,0);
}