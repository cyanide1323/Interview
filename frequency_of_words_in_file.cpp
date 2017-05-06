// cpp code to find the frequency of words in a given file

 
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

struct trieNode{
	bool end;
	int frequency;
	trienode*  child[26];
	int minIndex;
};

struct minHeapNode{
	int frequency;
	char *word;
	trienode *root;
};

struct minHeap{
	int capacity;
	int count; 
	minHeapNode *array;
};

void swapMinHeapNodes ( minHeapNode* a, minHeapNode* b )
{
    minHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

trienode* newtrieNode(){
	
	trieNode *temp = new trieNode;

	temp.isEnd=false;
	temp.frequency=0;
	temp.minIndex=-1;
	for(int i=0;i<26;i++) temp->child=NULL;

	return temp;
}

minHeapNode* newMinHeap(int capacity){

	minHeap *temp = new minHeap;
	temp->capacity = capacity;
	temp->count = 0;
	temp->array = new minHeapNode[minHeap->capacity];

	return temp;
}

// insert into the trie node
void insertTrieNode(trieNode *trieRoot, minHeap,char *word, char *dupword){
	if(!trieRoot) trieRoot = newtrieNode();
	if(word!='\0')  insertTrieNode(trieRoot->child[toLower(*word)-97],minHeap,word+1,dupword);
	else {
		if(trieRoot->isEnd) trieNode->frequency++;
		else{
			trieNode->isEnd=true;
			trieNode->frequency++;
		}
	}
	insertInMinHeap( minHeap, trieRoot, dupWord );
}

void insertInMinHeap(trieNode *trieRoot, char *dupword){
	if(trieRoot[minIndex]!=-1){
		minHeap->array[]
	}
}


int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 