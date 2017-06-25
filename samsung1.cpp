// finding loop in the graph 

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
 

bool prime[100001];

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

long dp[1001][1001];

int path[1001][1001];

void printAllPaths(int i,int j,int n,int m){
    path[i][j]=1;
    if(i==n-1 and j==m-1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(path[i][j])
                    cout<<i+1<<" "<<j+1<<endl;
        }
    }
    if(i+1<n and j+1<m and dp[i+1][j+1]!=0)
        printAllPaths(i+1,j+1,n,m);
    else if(i+1<n and dp[i+1][j]!=0)
        printAllPaths(i+1,j,n,m);
    else if(j+1<m and dp[i][j+1]!=0)
        printAllPaths(i,j+1,n,m);
    path[i][j]=0;
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    seive(100000);
    int n,m; cin>>n>>m;
    int arr[n][m];
   
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
         cin>>arr[i][j];
         dp[i][j]=0;
    }  

    bool flag = false;

    dp[0][0]=1;
    for(int i=1;i<n;i++){
        if(!prime[arr[i][0]]) flag=true;
        if(flag)
            dp[i][0]=0;
        else 
            dp[i][0]=1;
    }

    flag = false;

    for(int j=1;j<m;j++){
        if(!prime[arr[0][j]]) flag=true;
        if(flag)
            dp[0][j]=0;
        else 
            dp[0][j]=1;
    } 

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){

            if(prime[arr[i][j]])

                dp[i][j]=((dp[i-1][j]+dp[i][j-1])%MOD + dp[i-1][j-1])%MOD;
            
            else dp[i][j]=0;
        }
    }
    
    cout<<dp[n-1][m-1]<<endl;
    if(dp[n-1][m-1]==0) return 0;
    
    printAllPaths(0,0,n,m);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  