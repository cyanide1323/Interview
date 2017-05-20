// This is the code to find minimum islands in the matrix well connected within



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
 
/*
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
*/
 
 
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,-1,1,0,1,-1,1,-1};

 
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

#define row 5
#define col 5

bool bound(int x,int y){
	return (x>=0 and x<row and y>=0 and y<col);
}

void bfs(int x,int y,bool done[][col], int arr[][col]){
	if(done[x][y] or arr[x][y]!=1) return;
	done[x][y]=1;
	for(int i=0;i<8;i++){
			int new_x = x+dx[i];
			int new_y = y+dy[i];
			if( bound(new_x,new_y) ) bfs(new_x,new_y,done,arr);
	}
	return;
}

int generate(int arr[][col], bool done[][col]){
	int elements = 0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(!done[i][j] and arr[i][j]!=0)
				{ bfs(i,j,done,arr); elements++; }
		}
	}
	return elements;
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
   	 int arr[row][col]= {  
   	 	{1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1} };

       bool done[row][col]= {  
       	{0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0} };

   	//for(int i=0;i<row;i++) for(int j=0;j<col;j++) { cin>>arr[i][j]; done[i][j]=0; }
   	cout<<"Minimum Islands are "<<generate(arr,done)<<endl;
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  

