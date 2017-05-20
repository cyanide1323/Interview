// This program is for sole use of classes in cpp and sorting an object

 
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
  )
            prime[len
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
	node *next;
};

class element{
	public:
		node *newNode(int data);
		bool find_loop(node *head);
		void remove_loop(node *head);
		void print(node *head);
};

node* element :: newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->next=NULL;
	return temp;
}

bool element :: find_loop(node *head){
	node *slow=head,*fast=head;

	while(slow and fast and fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) return 1;
	}
	return 0;
}

void element :: remove_loop(node *head){

}

void element :: print(node *head){
	while(head){
		cout<<head->next<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    element e;
    node *head = e.newNode(50);
    head->next = e.newNode(20);
    head->next->next = e.newNode(15);
    head->next->next->next = e.newNode(4);
    head->next->next->next->next = e.newNode(10);
  	head->next->next->next->next->next = head->next->next;
    cout<< e.find_loop(head) << endl;
    cout<< e.remove_loop(head) << endl;
    cout<< e.print(head);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 