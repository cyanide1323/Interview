// articulation bridge

#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define N 5

vector<vector<int> >graph(5);                    // declaring graph in 2d vector 

void articulationBridge(int u,int parent[],int low[],int disc[],bool visited[]){

	static int time = 0;
	
	visited[u]=true;
	disc[u] = low[u] = ++time;      				// for the first time both low and disc be equal to time
	
	for(int i=0;i<graph[u].size();i++){

		int v = graph[u][i];
		
		if(!visited[graph[u][i]]){
			
			parent[graph[u][i]]=u;
			articulationBridge(graph[u][i],parent,low,disc,visited);
			
			low[u]=min(low[u],low[v]);				// this condition with update the values of parents low after recursion trace back

			if(low[v]>low[u])
				cout<<u<<"  "<<v<<endl;				// if child can reach parents of parent then surely it forms the bridge or contains articulation point
		}
		else if(v!=parent[u])
			low[u]=min(low[u],disc[v]);				// here we update the  low of node if it can reach the parent of it's parent and not parent
	}
}

int main(){

	int parent[N],low[N],disc[N];
	bool visited[N];
	
	graph[1].push_back(0);
	graph[0].push_back(2);
	graph[2].push_back(1);
	graph[0].push_back(3);
	graph[3].push_back(4);

	for(int i=0;i<N;i++) visited[i]=false,parent[i]=-1;
	for(int i=0;i<N;i++)
		if(!visited[i]) articulationBridge(i,parent,low,disc,visited);
	return 0;
}