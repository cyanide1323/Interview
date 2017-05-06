 
// code has segmentation fault, please check 

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

#define ROW 4
#define COL 5

int kadane(int temp[],int row,int *up_row,int *down_row){
    int curr_sum=0,max_sum=INT_MIN; *down_row=-1;
    int local=0;
    for(int i=0;i<row;i++){

         if(curr_sum<0){
            curr_sum=0; 
            local=i+1;
        }

        else if(curr_sum+temp[i]>max_sum){
            max_sum = curr_sum+temp[i];
            *down_row=i; *up_row = local;
        }
       
    }
    if(*down_row!=-1) return max_sum;
    else { 
        curr_sum=temp[0]; *up_row=0; *down_row=0;
        for(int i=1;i<row;i++){
            if(temp[i]>curr_sum) {
                curr_sum=temp[i];
                *up_row=i ; *down_row=i;
            }
        }
    }
}

void max_rect(int arr[][COL]){
    int up_row,down_row,max_sum=INT_MIN;
    int final_left_col,final_right_col,final_up_row,final_down_row;
    for(int i=0;i<COL;i++){
        int temp[ROW];
        for(int j=i+1;j<COL;i++){
            memset(temp,0,sizeof(temp));
            for(int k=0;k<ROW;k++) temp[i]+=arr[i][j];
            int sum = kadane(temp,ROW,&up_row,&down_row);
            if(sum>max_sum){
                final_left_col=i; final_right_col=j;
                final_up_row=up_row; final_down_row=down_row;
                max_sum=sum;
            }
        }
    }
    cout<<"maximum rectangle found at these rows and columns "<< final_up_row << "  " << final_down_row << "  " << final_left_col << "  " << final_right_col << endl;
}

int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
 
    max_rect(M);
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 