// flipkart question 

// applying djikstras's alogirthm implemented before

// lru cache design in cpp

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <deque>
#include <cstdio>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <utility>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
// definitions
 
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp(a,b) make_pair(a,b)
#define pf(a) push_front(a)
#define pb(a) push_back(a)
#define ppf() pop_front()
#define ppb() pop_back()
#define ll long long int
#define ull unsigned long long
#define s(a) scanf("%d",&a)
#define ss(a,b) scanf("%d%d",&a,&b)
#define sl(a) scanf("%lld",&a)
#define clr(x) memset(x,0,sizeof(x))
#define FOR(x,y,z) for(int x=y;x<z;x++)
#define RFOR(x,y,z) for(int x=y;y>=z;x--)
#define bs(a,b,c) binary_search(a,b,c)
#define ub(a,b,c) upper_bound(a,b,c)
#define lb(a,b,c) lower_bound(a,b,c)
const int INF = (int)1e9;
const int NINF = -(int)1e9;
const int MOD = (int)1e9 + 7;
const double PI=acos(-1.0);
const double EPS=1e-11;
 
 
using namespace std;
 

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
 
 
/* 
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,-1,1,0,1,-1,1,-1};
*/
 
template<class T>
T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
 
template<class T>
T lcd(T a,T b) { return abs(a*b)/gcd(a,b); }
 
/*
void seive(int N)
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=false;
     
    for(int i = 4; i < N; i+= 2) prime[i]=false;
     
    for(int i = 3; i*i < N;i+= 2)
    if(prime[i])
        for(int j = i*i; j < N; j+= (i<<1))
            prime[j]=false;
}
*/
 
/*
template<class T>
T pow(T x,T n)
{
    if(n==0) return 1;
    T r=1,y=x;
    while(n>1)
    {
        //if(r>=l) { flag=true; break; }
        if(n&1) { r*=y;  }
        y*=y; 
        n/=2;
    }
    r*=y; 
    return r;
}
*/

struct node{
	int id;
	string name;
	int salary;
	int rating;
	bool isHead;
};

node* newNode(int id,string name,int salary,int rating,bool isHead){
	node *temp = new node;
	temp->id = id;
	temp->name = name;
	temp->salary = salary;
	temp->rating = rating;
	temp->isHead = isHead;

	return temp;
}

int PrepareFiringList(map<node*,vector<node*> >&graph,int k,node *start_manager){
	
	priority_queue<node*> firing_list;
	queue<node*> q;
	q.push(start_manager);
	
	while(!q.size()){
		node *begin = q.front();
		q.pop();
		for(int i=0;i<graph[begin].size();i++){
			q.push(graph[begin][i]);
			if(!firing_list.empty()) cout << "Top of the firing_list " << firing_list.top()->id << endl;
			cout << "current id is " << graph[begin][i]->id << endl;
			if(firing_list.size()<k)
				firing_list.push(graph[begin][i]);
			else{

				node *temp1 = firing_list.top();
				node *temp2 = graph[begin][i];

				if(temp2->rating > temp1->rating or (temp2->rating==temp1->rating and temp2->salary>temp1->salary)){
					firing_list.pop();
					firing_list.push(temp2);
				}
			}
		}
	}
	int val=0;
	cout<<"Id  Rating  salary\n";
	while(!firing_list.empty()){
		node *temp = firing_list.top();
		firing_list.pop();
		val+=temp->salary;
		//cout << temp->id << "    " << temp->rating << "       " << temp->salary << endl;
	}
	return val;
}

int main(int argc,char *argv[]){

    //clock_t startTime = clock();
	int total_saving = 0; int k=2; 
    node *start_manager; //cin >> start_manager;

	map<node*,vector<node*> > graph;
	
	node *e1 = newNode(1,"e1",80000,-1,true);
	node *e2 = newNode(2,"e2",40000,3,false);
	node *e3 = newNode(3,"e3",50000,2,false);
	node *e4 = newNode(4,"e4",30000,3,false);
	node *e5 = newNode(5,"e5",45000,4,false);
	node *e6 = newNode(6,"e6",51000,5,false);
	node *e7 = newNode(7,"e7",63000,2,false);

	//graph.insert(make_pair(e1,vector<node*>() ));
	graph[e1].push_back(e2);
	graph[e1].push_back(e3);
	graph[e1].push_back(e4);
	graph[e1].push_back(e5);
	graph[e2].push_back(e6);
	graph[e2].push_back(e7);

	cout << graph[e1][0]->id << endl;

	start_manager = e1;
	total_saving = PrepareFiringList(graph,k,start_manager);
	
	cout<<"Total saving is " << total_saving << endl;
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  

