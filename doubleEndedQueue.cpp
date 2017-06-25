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

struct queu{
	int data; 
	queu *next,*prev;
};

int capacity = 0;
int max_capacity = 5;

queu* newqueu(int data){

	queu *temp = new queu;
	temp->data = data;
	temp->next = temp->prev = NULL;

	return temp;
}

void pop(queu *head,queu *rear){
    if(!head){
        cout<<"NO item to delete\n";
        return;
    }

    else if(head==rear){
        queu *val = head;
        val->next=val->prev=NULL;
        head=rear=NULL;
        free(val);
    }

    else{
        queu *val = rear;
        val->prev->next=NULL;
        rear=val->prev;
        val->prev=NULL;
        free(val);
    }
    capacity--;
}

void push(queu *head,queu *rear,int data){

    queu *temp = newqueu(data);

    if(!head){
        //cout<<capacity<<"  queue capacity "<<max_capacity<<endl;
        head=temp;
        rear=temp;
    }
    
    else if(capacity<max_capacity){
        
        cout<<"this are atleast one node\n";
        head->prev=temp;
        //head=temp;
        //cout<<"head ->data is "<<head->data<<endl;
        temp->next=head;
        head=temp;
    }
    
    else if(capacity>=max_capacity){
        
        pop(head,rear);
        head->prev=temp;
        temp->next=head; 
        head=temp;
    
    } 

    //cout<<head->data<<" front and rear "<<rear->data<<endl;

    capacity++;
}

int main(int argc,char *argv[]){

    //clock_t startTime = clock();
    queu *head=NULL;
    queu *rear=NULL;
    int n; cin>>n; 
    while(n--){
        int type ; cin>> type;
        if(type==0){
            int val; cin>>val;
            push(head,rear,val);
            if(head and rear) cout<<head->data<<"   "<<rear->data<<endl;
        }
        else{
            pop(head,rear);
            if(head and rear) cout<<head->data<<"   "<<rear->data<<endl;
        }
    }
    pop(head,rear);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  

/* move the page to the front 
1. This page is only page in the queu
2. This page is the last page in the queu
3. This page is alread the first queu in the queu
4. This page is in the middle of the queu

Inserting the new queu in the linkedlist
If capacity is under control
1. We don't have any item in the queu meaning head and rear are NULL
2. We have only one item in the quee and rear and end are equal
3. We have more than one item in the queu and head and read are not equal

If capcity is not under control then we have to delete the last item
and is such case head and read will never be equal
*/