// flipkart 3

#include <bits/stdc++.h>
using namespace std;

int main(){
	// build the graph
	int nodes,tuples;
	cin>>nodes>>tuples;
	bool E1,E2,E4,E5,present[nodes];
	int parent[nodes],childrens[nodes],roots=nodes;
	memset(parent,-1,sizeof(parent));
	memset(childrens,0,sizeof(childrens));
	memset(present,false,sizeof(present));

	while(tuples--){
		int a,b; cin>>a>>b;
		if(present[a] and present[b] and parent[b]==a)
			E2=1;
		present[a]=1; present[b]=1;
		if(parent[b]!=-1 and parent[b]!=a) E5=true;
		if(parent[b]==-1) roots--;
		parent[b]=a; childrens[a]++;
		if(childrens[a]>2) E1=true; 
	}

	E4 = (roots==1)?false:true;

	if(E1) cout<<"E1\n";

	if(E2) cout<<"E2\n";
	

	//if(E3(graph,visited)) cout<<"cycle is present in the graph\n";
	//else cout<<"cycle is not preesnt in the graph\n";

	if(E4) cout<<"E4\n";
	
	if(E5) cout<<"E5\n";
	
	if(!E1 and !E2 and !E4 and !E5)
		cout<<"Success\n";

	return 0;
}