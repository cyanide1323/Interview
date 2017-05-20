// view of binary tree from all sides like top, bottom, left, right and boundary traversal

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
	node *left,*right;
};


class Print{
	
	public:
		
		node* newNode(int data);
		
		
		void leftView(node *root,int a,int *b);
		void rightView(node *root,int a,int *b);
		
		void topView(node *root);
		void leftSide(node *root,int a,int *b);
		void rightSide(node *root,int a,int *b);
		
		void boundaryTraversal(node *root);
		void leftTraversal(node *root);
		void bottomTraversal(node *root);
		void rightTraversal(node *root);
		
};

node* Print :: newNode(int data){
	node *temp = new node;
	temp->data= data;
	temp->left = temp->right = NULL;
	return temp;
}

void Print :: leftView(node *root,int currHeight,int *maxHeight){
	
	if(!root) return;
	if( *maxHeight < currHeight and (!root->left and !root->right) ){
		cout<<root->data<<" ";
		*maxHeight=max(*maxHeight,currHeight);
	}
	leftView(root->left,currHeight+1,maxHeight);
	leftView(root->right,currHeight+1,maxHeight);
}

void Print :: rightView(node *root,int currHeight,int *maxHeight){
	
	if(!root) return;
	if( *maxHeight < currHeight and (!root->left and !root->right) ){
		cout<<root->data<<" ";
		*maxHeight=max(*maxHeight,currHeight);
	}
	rightView(root->right,currHeight+1,maxHeight);
	rightView(root->left,currHeight+1,maxHeight);
}


vector<int> elements;
void Print :: leftSide(node *root,int currLeft, int *maxLeft){

	//cout<<currLeft<<"  "<<maxLeft<<endl;

	if(!root) return;
	if(*maxLeft<currLeft){
		elements.push_back(root->data);
		*maxLeft=currLeft;
	}
	leftSide(root->left,currLeft+1,maxLeft);
	leftSide(root->right,currLeft-1,maxLeft);
}

void Print :: rightSide(node *root,int currRight, int *maxRight){
	if(!root) return;
	if(*maxRight<currRight){
		cout<<root->data<<"  ";
		*maxRight=currRight;
	}
	rightSide(root->right,currRight+1,maxRight);
	rightSide(root->left,currRight-1,maxRight);
}

void Print :: topView(node *root){
	if(!root) return ;  
	int currLeft=1,maxLeft=0,currRight=1,maxRight=1;
	leftSide(root,currLeft,&maxLeft); reverse(elements.begin(),elements.end());
	for(int i=0;i<elements.size();i++) cout<<elements[i]<<" ";
	rightSide(root,currRight,&maxRight);
	cout<<endl;
}

void Print :: bottomTraversal(node *root){
	if(!root) return;
	if(root->left==NULL and root->right==NULL) cout<<root->data<<"  ";
	bottomTraversal(root->left);
	bottomTraversal(root->right);
}

void Print :: leftTraversal(node *root){
	
	if(!root) return;
	
	if(root->left){
		cout<<root->data<<" ";
		leftTraversal(root->left);
	} 
	else if(root->left){
		cout<<root->data<<" ";
		leftTraversal(root->right);
	}
}

void Print :: rightTraversal(node *root){
	
	if(!root) return;
	
	if(root->right){
		rightTraversal(root->right);
		cout<<root->data<<"  ";
	} 
	else if(root->left){
		rightTraversal(root->left);
		cout<<root->data<<"  ";
	} 

	return;
}

void Print :: boundaryTraversal(node *root){
	
	if(!root) return;
	
	if(root) cout<<root->data<<" ";
	
	leftTraversal(root->left);
	bottomTraversal(root);
	rightTraversal(root->right);
	
	cout<<"\n";
	return;
}

void recursiveInorder(node *root){
	if(!root) return;
	recursiveInorder(root->left);
	cout<<root->data<<"  ";
	recursiveInorder(root->right); 
}

void iterativeInorder(node *root){
	if(!root) return;
	stack<node*> st;
	st.push(root);
	while(1){
		if(st.empty()) break;
		if(root->left) { root=root->left;st.push(root); }
		if(!root and !st.empty()) { node *temp = st.top(); cout<<data->data<<"  "; root=root->right;}
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    Print p; 
    node *root = p.newNode(12);
    root->left = p.newNode(10);
    root->right = p.newNode(30);
    root->right->left = p.newNode(25);
    root->right->right = p.newNode(40);

 	int currHeight=1,maxHeight=0;
    leftView(root,currHeight,&maxHeight);
    currHeight=1;maxHeight=0; cout<<endl;
    rightView(root,currHeight,&maxHeight); 
 
 	p.topView(root);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  

