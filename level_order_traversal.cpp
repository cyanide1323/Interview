// level order traversal 

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
	node *left,*right;
};

class element{
	public:
		node *newNode(int data);
		void level_order_traversal(node *root);
		void zigzag_level_order_traversal(node *root);
		void recursive(node *root);
		void printlevel(node *root,int k);
		int height(node *root);
};

int height(node *root){
	if(!root) return 0;
	return max(height(root->left),height(root->right))+1;
}

void recursive(node *root){
	if(!root) return; 
	//bool flag=false;
	int ht = height(root);
	for(int i=0;i<=ht;i++){
		printlevel(root,i);
	}	
}

void printlevel(node *root,int k){
	if(!root) return;

	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	if(flag){
		printlevel(root->left,k-1);
		printlevel(root->right,k-1);
	}
	else {
		printlevel(root->right,k-1);
		printlevel(root->left,k-1);
	}
	flag != flag;
}

void element :: level_order_traversal(node *root){
	if(!root) return;
	queue<node*> q; 
	q.push(root);
	while(!q.empty()){
		node *temp = q.front(); q.pop();
		cout<<temp->data<<" ";
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	return;
}

void element :: zigzag_level_order_traversal(node *root){
	if(!root) return;
	stack<node*> st1,st2;
	st1.push(root);
	while(1){
		
		if(st1.empty() and st2.empty()) break;

		if(!st1.empty()){
			node *temp = st1.top(); st1.pop();
			cout<<temp->data<<"  ";
			if(temp->left)  st2.push(temp->left);
			if(temp->right) st2.push(temp->right);
		}
		else if(!st2.empty()){
			node *temp = st2.top(); st2.pop();
			cout<<temp->data<<"  ";
			if(temp->right) st1.push(temp->right);
			if(temp->left) st1.push(temp->left);
		}
	
	}
}



node* element :: newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->left=temp->right=NULL;
	return temp;
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    element e;
    struct node* root = e.newNode(1);
    root->left        = e.newNode(2);
    root->right       = e.newNode(3);
    root->left->left  = e.newNode(4);
    root->left->right = e.newNode(5);
    e.level_order_traversal(root); cout<<endl;
    e.zigzag_level_order_traversal(root);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 