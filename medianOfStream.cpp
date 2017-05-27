// not done due to various bugs

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

int main(int argc,char *argv[]){

    //clock_t startTime = clock();
    int n=12;
    int arr[]
    priority_queue<int,std::vector<int>, std::less<int> > min_val;              // binary heap of min type
    priority_queue<int,std::vector<int>, std::greater<int> > max_val;           // binary heap of max type
    int size1=min_val.size();
    int size2=max_val.size();
    //max_val.clear(); min_val.clear();
    while(n--){
    

        if(size2==0){
            max_val.push(num);
            cout<<"Median is "<<num<<endl;
            continue;
        }
        else if(size1==0){
             min_val.push(num);
             int temp = max_val.top()+min_val.top();
             cout<<"Median is "<<temp/2<<endl;
             continue;
         }

        cout<<size2<<" "<<size1<<endl;
        
        if(size2>size1){

            cout<<"Median is in max"<<max_val.top()<<endl;
            int value = max_val.top();
            if(num>=value) min_val.push(num);
            else{
                max_val.push(num);
                min_val.push(value);
            }
        }
        else if(size1>size2){

            cout<<"Median is min"<<min_val.top()<<endl;
            int value = min_val.top();
            if(num<=value) max_val.push(num);
            else{
                min_val.pop();
                max_val.push(value);
                min_val.push(num);
            }

        }
        else{
            int value = (min_val.top()+max_val.top())/2;
            cout<<"Median is average"<<value<<endl;
            if(num>=max_val.top()) min_val.push(num);
            else max_val.push(num); 
        }
    }

    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  