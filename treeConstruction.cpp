// construction of binary tree from preorder and inorder traversal given



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

node* newNode(int data){
	node *temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}

int search(int inorder[],int key,int start,int end){
	for(int i=start;i<=end;i++)
		if(inorder[i]==key) return i;
	return -1;
}


node* develop(int preorder[],int inorder[],int start,int end){


	static int preIndex = 0;
	if(start>end) return NULL;
	
	node *Troot = newNode(preorder[preIndex++]);
	if(start==end) return Troot;

	int index = search(inorder,Troot->data,start,end);

	Troot->left = develop(preorder,inorder,start,index-1);
	Troot->right = develop(preorder,inorder,index+1,end);

	return Troot;

}

node* develop2(int postorder[],int inorder[],int start,int end){

	static int preIndex = end;
	if(start>end) return NULL;
	
	node *Troot = newNode(postorder[preIndex--]);
	if(start==end) return Troot;

	int index = search(inorder,Troot->data,start,end);

	
	Troot->right = develop2(postorder,inorder,index+1,end);
	Troot->left = develop2(postorder,inorder,start,index-1);


	return Troot;

}


void print(node *root){
	if(!root) return;
	cout<<root->data<<"  ";
	print(root->left);
	print(root->right);
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
	//int preorder[]={10,5,2,6,14,12,15};
	int inorder[]={4, 8, 2, 5, 1, 6, 3, 7};
	int postorder[]={8, 4, 5, 2, 6, 7, 3, 1};
	int len = sizeof(postorder)/sizeof(postorder[0]);
	node *root=develop2(postorder,inorder,0,len-1);
	print(root);  cout<<endl;
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  