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
	int data; 
	node *next,*prev;
}*head,*rear;

node* newNode(int data){

	node *temp = new node;
	temp->data = data;
	temp->next = temp->prev = NULL;

	return temp;
}

void print(node *start){
	while(start!=NULL){
		cout<<start->data<<" ";
		start=start->next;
	}
	cout<<endl;
}

void enqueue(node *head, node *rear, node *temp){
	
	if(!head and !rear){
		head = rear = temp;
		return;
	}

	temp -> next = head;
	head -> prev = temp;
	head = temp;
}

void dequeue(node *head, node *rear, node *temp){
	if(!head or !rear) {
		cout<<"No element in the queue\n";
	}
	else if(head == rear){
		cout<<"Only element deleted\n";
		delete head;
	}
	else{
		node *deletableNode = rear;
		node *previous = rear->prev;
		previous -> next = NULL;
		rear = rear->prev;
		delete deletableNode;
	}
}

int main(int argc,char *argv[]){

    //clock_t startTime = clock();
    map<int,node*> page_link;  // creation of the map
    head=rear=NULL; int capacity = 10,curr_capacity=0;   // head pointer, rear point equal to null initially 
    int demands; cin>>demands; // get the number of page demands
    
    while(demands--){
    	
    	int page_demand; cin>>page_demand;                   // get the current demand
    	
    	if(page_link.find(page_demand)!=page_link.end()){    // check if current demand is in the cache
    		
    		node *temp = page_link[page_demand];			// acquiring the link of the current node from map into the queue
    		// move the page to the front 
    		if(head==temp) continue;						// if it is the only node in the queue, no need to do anything
    		else if(rear==temp){
    			//  extract node from the last 						// checking if the current node comes at the last, have to take it to the front
    			node *previous = rear->prev;
    			previous -> next = NULL;
    			rear -> next = head;
    			head -> prev = rear;
    			head = rear;
    			rear = previous;

    		}else{
    			//extracting node from it's place						// all other cases
    			node *previous = temp -> prev;
    			node *after = temp -> next;
    			previous -> next = after;
    			after -> prev = previous;
    			temp -> next = head;
    			head -> prev = temp;
    			head = temp;
    
    		}

    		//temp->next=head;
    		//head=temp;
    	}

    	else{
    		node *temp = newNode(page_demand);
    		// insert the page to front 
    		if(curr_capacity<capacity){
    			// enqueue the node
    			enqueue(head, rear, temp);
    		}
    		else{
    			// dequeue the node
    			dequeue(head, rear, temp);
    			// enq ueue the node
    			enqueue(head, rear, temp);
    		}
    		page_link.insert(make_pair(page_demand,temp));  curr_capacity++;  			// inserting the node in the map with link in queue and increasing the current capcity by 1
    	}
    	print(head);
    }
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  

/* move the page to the front 
1. This page is only page in the queue
2. This page is the last page in the queue
3. This page is alread the first node in the queue
4. This page is in the middle of the queue

Inserting the new node in the linkedlist
If capacity is under control
1. We don't have any item in the queue meaning head and rear are NULL
2. We have only one item in the quee and rear and end are equal
3. We have more than one item in the queue and head and read are not equal

If capcity is not under control then we have to delete the last item
and is such case head and read will never be equal
*/