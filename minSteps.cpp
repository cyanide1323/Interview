// minimum jumps to reach destination


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

int findSteps(int arr[],int n){
	int dp[n]; for(int i=0;i<n;i++) dp[i]=1000;
	dp[0]=0;

	for(int i=0;i<n;i++){
		int jump = arr[i];
		for(int j=i+1;j<=min(n-1,i+jump);j++){
			cout<<i<<"  "<<j<<endl;
			dp[j]=min(dp[j],dp[i]+1);
		}
	}
	for(int i=0;i<n;i++)
		cout<<dp[i]<<"  ";
	cout<<endl;
	return dp[n-1];
}

int findSteps2(int arr[],int n){
	int dp[n]; 
	dp[0]=0;
	if(arr[0]==0) return -1;
	else{
		for(int j=1;j<n;j++){
			dp[j]=1000;
			for(int i=0;i<j;i++){
				if(j<=i+arr[i] and dp[i]!=1000)
					dp[j]=min(dp[j],arr[i]+1);
			}
		}
	}
	return dp[n-1];
}

int main(int argc,char *argv[]){

    //clock_t startTime = clock();
 	int n=11; int arr[n]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}; 
    cout<<findSteps2(arr,n)<<endl;
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  