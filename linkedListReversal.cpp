

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
    node *next;
};

node* newNode(int data){
    
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;

    return temp;
}


node* reverseLinkedList(node *root,node **head1){

    node *prev=NULL,*curr=*head1,*coming;
    while(curr){

        coming = curr->next;
        curr->next = prev;
        prev = curr;
        curr = coming;
        
    }
    *head1 = prev;
}

void recursiveReversal(node *prev,node *curr,node **head1){

    if(curr->next==NULL){
        *head1=curr;
        curr->next=prev;
        return;
    }
    else recursiveReversal(curr,curr->next,head1);
    curr->next = prev;
    return;
}

void printList(node *root){
    while(root){
        cout<<root->data<<"  ";
        root=root->next;
    }
    cout<<endl;
}

node* reverseKGaps(node *root,int k){

    node *prev=NULL,*curr=root,*next;
    int temp = 0;
    while(curr and temp<k){

            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            temp++;
            //if(prev!=NULL) cout<<"curr and next are "<<curr->data<<"  "<<curr->next->data<<endl;
            //else cout<<"curr and next are "<<curr->data<<"  NULL\n";
        }
    
        if(next) root->next = reverseKGaps(next,k);

        return prev;
        //if(cnt==1) *head1=root;
        //root->next=next;
        //root=curr;
        //temp=k;
        //while(temp-- and curr) 
          //  prev=curr,curr=curr->next;
    
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
  	node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    reverseLinkedList(head1,&head1);
    printList(head1);
    recursiveReversal(NULL,head1,&head1);
    printList(head1);
    head1=reverseKGaps(head1,2);
    printList(head1);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  