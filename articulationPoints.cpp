// articulation points

#include <bits/stdc++.h>
using namespace std;
#define N 5

vector<vector<int> >graph(5);                    // declaring graph in 2d vector 

void articulationPoint(int u,int parent[],int low[],int disc[],bool visited[],bool articulation[],int children[]){

	static int time = 0;
	
	visited[u]=true;
	disc[u] = low[u] = ++time;      				// for the first time both low and disc be equal to time
	
	for(int i=0;i<graph[u].size();i++){

		int v = graph[u][i];
		
		if(!visited[graph[u][i]]){
			
			children[u]++;
			parent[graph[u][i]]=u;
			
			articulationPoint(graph[u][i],parent,low,disc,visited,articulation,children);
			
			low[u]=min(low[u],low[v]);				// this condition with update the values of parents low after recursion trace back
			if(parent[u]=-1 and children[u]>1) 
				articulation[u]=1;

			if(low[v]>low[u])
				articulation[v]=1;				// if child can reach parents of parent then surely it forms the bridge or contains articulation point
		}
		else if(v!=parent[u])
			low[u]=min(low[u],disc[v]);				// here we update the  low of node if it can reach the parent of it's parent and not parent
	}
}

int main(){

	int parent[N],low[N],disc[N],children[N];
	bool visited[N]; bool articulation[N];

	graph[1].push_back(0);
	graph[0].push_back(2);
	graph[2].push_back(1);
	graph[0].push_back(3);
	graph[3].push_back(4);

	for(int i=0;i<N;i++) visited[i]=false,parent[i]=-1,articulation[i]=false,children[i]=0;
	for(int i=0;i<N;i++)
		if(!visited[i]) articulationPoint(i,parent,low,disc,visited,articulation,children);
	for(int i=0;i<N;i++)
		if(articulation[i]) cout<<i<<" ";
	cout<<endl;
	return 0;
}