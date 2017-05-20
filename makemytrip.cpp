 // PLEASE COMPLETE IT IT'S VERY URGENT


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


char arr[100][100];
bool visited[100][100];
int row,col;

bool check(int i,int j,int row, int col){
    return (i>=0 and i<row and j>=0 and j<col and !visited[i][j] and (arr[i][j]!='D'));
}



bool check_path(int row,int col,pii mouse,pii cheese){

    cout<<"Mouse coordinates are "<<mouse.first<<"  "<<mouse.second<<endl;
    
    if(mouse.first==cheese.first and mouse.second==cheese.second)
        return true;

    bool answer = false,result=false;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mouse.first = mouse.first+dx[i];
            mouse.second = mouse.second+dy[j];
            cout<<"New coordinates are "<<mouse.first<<"  "<<mouse.second<<endl;
            if(check(mouse.first,mouse.second,row,col)){
                visited[mouse.first][mouse.second]=1;
                result = result or check_path(row,col,mouse,cheese);
            }
            if(result) { answer=true; break; } 
        }
        if(answer) break;
    }
    return answer;
}


int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    int tc; cin>>tc;
    while(tc--){
        cin>>row>>col; getchar();
        char arr[row][col]; bool visited[row][col]; pii mouse,cheese;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                cin>>arr[i][j]; visited[i][j]=0;
                if(arr[i][j]=='A') { mouse.first = i; mouse.second=j; }
                if(arr[i][j]=='B') { cheese.first=i; cheese.second=j; }
            }
        }
        cout<<check_path(row,col,mouse,cheese)<<endl;
    }
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 