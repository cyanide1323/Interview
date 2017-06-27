// clone a binary tree

// seocnd approach using maps and easy way

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

/*

	learn the use of file stream
	
	// __gcd(a,b) also works
	
	// are all of the elements positive ?
	all_of(first,first+n,ispositive());

	// is there at least one positive element ?
	any_of(first,first+n,ispositive());

	// are none of the elements positive ?
	none_of(first,first+n,ispositive());
*/

/*
	ifstream myfile("file_name.txt");
	ofstream myfile("file_name.txt");
	
	myfile.open();
	
	while(getline(myfile,str)) {}
	myfile >> str;
*/

struct node{
	int data;
	node *left,*right,*random;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->left = temp->random = temp->right = NULL;
	return temp;
}

void print(node *root){
	if(!root) return;
	print(root->left);
	if(root->random) cout<<root->data<<"  "<<root->random->data<<endl;
	else cout<<root->data<<"  "<<"NULL\n";
	print(root->right);
}

//==================== This method uses O(n) space ==========================
node* create(node *root,map<node*,node*>&mymap){
	if(!root) return NULL; 
	node *copy = newNode(root->data);
	mymap.insert(make_pair(root,copy));
	copy->left=create(root->left,mymap);
	copy->right=create(root->right,mymap);
	return copy;
}

void linkRandom(node *original,node *copy,map<node*,node*>&mymap){
	if(!original) return;
	copy->random=mymap[original->random];
	linkRandom(original->left,copy->left,mymap);
	linkRandom(original->right,copy->right,mymap);
}

// ====================== This method does not use any space but modifies tree ===

node* createLeftRight(node *original){
	
	if(!original) return NULL;
	node *copy = newNode(original->data);
	node *left = original->left;
	original->left=copy;
	copy->left=left;
	
	if(left)
		left->left=createLeftRight(left);

	if(original->right)
		left->right=createLeftRight(original->right);

	return original->left;
}




int main(int argc,char *argv[]){

    //clock_t startTime = clock();
    node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;
	map<node*,node*> mymap;
    node *copy = createLeftRight(tree);
    //linkRandom(tree,copy,mymap);
    print(tree); 
    cout<<"------------------------------------\n";
    //print(copy);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  