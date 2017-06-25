// clone a linked list using next and arbit pointer

// not done due to various bugs

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
	node *next,*random;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->next = temp->random = NULL;
	return temp;
}

void print(node *start){
	while(start){
		cout<<start->data<<"  ";
		start=start->next;
	}
}

int main(int argc,char *argv[]){

    //clock_t startTime = clock();

    // create a linked list with clonning
	node* start = newNode(1);
    start->next = newNode(2);
    start->next->next = newNode(3);
    start->next->next->next = newNode(4);
    start->next->next->next->next = newNode(5);

    start->random = start->next->next;
 
    // 2's random points to 1
    start->next->random = start;
 
    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;
 
    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;

    // create the copy linkedlist
    node *original = start,*copy,*copy_start;
    int cnt=0;
    
    while(original){

    	copy=newNode(original->data);
    	copy->next = original->next;
    	original->next=copy;
   		original=copy->next;
    
    }
   	
   	original=start; copy=start->next;
   	while(original){
   		original->next->random = original->random->next;
   		original=original->next?original->next->next:original->next;
   	}
   
   	original = start; copy_start=start->next; copy=start->next;
  	while(original and copy){
  		
  		original->next=original->next?original->next->next:original->next;
  		copy->next=copy->next?copy->next->next:copy->next;
  		original=original->next;
  		copy=copy->next;
  	}

   	original=start; copy=copy_start;
   	while(original) { cout<<original->data<<"  "<<original->random->data<<endl; original=original->next; }
   	cout<<"=== Above original ======================= Below copy ===="<<endl;
   	while(copy) { cout<<copy->data<<"  "<<copy->random->data<<endl; copy=copy->next; }
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  