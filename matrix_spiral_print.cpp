// spiral printing of the matrix

 
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
    r*=y; ,
    return r;
}
*/

#define R 3
#define C 6

void rotate_matrix(int arr[R][C]){
    
    int i,j,start_i=0,start_j=0,stop_i=R-1,stop_j=C-1;
    
    while(start_i<=stop_i and start_j<=stop_j){
        
        for(j=start_j;j<=stop_j;j++) {  
            cout<<arr[start_i][j]<<" "; 
        }
        start_i=start_i+1; cout<<endl;
        
        for(i=start_i;i<=stop_i;i++) {
         cout<<arr[i][stop_j]<<" ";
        }
        stop_j=stop_j-1; cout<<endl;
     
        //if(start_i<stop_i){   
            for(j=stop_j;j>=start_j;j--) { 
                cout<<arr[stop_i][j]<<" "; 
                }
        //}
        stop_i=stop_i-1; cout<<endl;
        
        //if(start_j<stop_j){
            for(i=stop_i;i>=start_i;i--) { 
                cout<<arr[i][start_j]<<" "; 
            }
        //}
        start_j=start_j+1; cout<<endl;

        cout << "start and stop :: "<<start_i << "  " << stop_i << "  " << start_j << "  " << stop_j << endl;
    }
}

/*
void print(int arr[][],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}
*/

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
	int arr[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
    //print(matrix,n);
    rotate_matrix(arr);
    //print(matrix,n);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 