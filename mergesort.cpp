// This is the algorithm of merge sort

// find loop in the linked list

 
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

int merge(int arr[], int low, int mid, int high){
	
	int i,j,k,n1,n2,inv_cnt=0;
	n1 = mid-low+1;
	n2 = high-mid;
	int l[n1],r[n2];
	i=0; j=0; k=0;
	while(i<n1) { l[i]=arr[low+i]; i++; }
	while(j<n2) { r[j]=arr[mid+1+j]; j++; }
	i=0; j=0;
	while(i<n1 and j<n2){
		if(l[i]<=r[j]) { arr[k]=l[i]; i++; }
		else { arr[k]=r[j]; j++; inv_cnt+=(mid-i); }
		k++; 
	}

	while(i<n1) { arr[k]=l[i]; i++; k++; }
	while(j<n2) { arr[k]=r[j]; j++; k++; }

	return inv_cnt;
}

int mergesort(int arr[],int low,int high){
	int inv_cnt=0;
	if(low < high){
		int mid = low+(high-1)/2;
		inv_cnt=mergesort(arr,low,mid);
		inv_cnt+=mergesort(arr,mid+1,high);
		inv_cnt+=merge(arr,low,mid,high);
	}
	return inv_cnt;
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    int n; cin>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 