<<<<<<< HEAD
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
int main(int argc,char *argv[])
{
    //clock_t startTime = clock();
    int digits; cin>>digits;
    int present[10]; 
    for(int i=0;i<10;i++) present[i]=0;
    
    int ones,twos; bool flag1=false; bool flag2=false;
    for(int i=0;i<digits;i++) 
    {   
        int var; cin>>var; 
        present[var]=1; 
        if( (var%3)==1 and flag1==false) { ones=var; flag1=true; }
        if( (var%3)==2 and flag2==false) { twos=var; flag2=true; }
         
    }
    
   //cout<<"ones and twos are "<<ones<<"  "<<twos<<endl;
  
    int len; cin>>len;
    vector<int> num; num.clear();

    if(digits==1 and present[0]==1){
        for(int j=0;j<len;j++) cout<<"0";
        cout<<endl; return 0;
    }
    
    for(int i=0;i<len;i++){
        int temp = num.size();
        if(temp>=len) break;
    
        for(int j=0;j<10;j++){
            
            if(!present[j]) continue;
                
            if(j==0 and i==0) continue;
            
            else if( (j%3)==0 ) {
                    num.push_back(j); break; 
                }
            
                else {    
                    int rem = j%3; int var = (int)num.size();
                    if(rem==1 and flag2==true and var<=(len-2)) { num.push_back(j); num.push_back(twos); break; }
                    if(rem==2 and flag1==true and var<=(len-2)) { num.push_back(j); num.push_back(ones); break; }
                }
            
            //else continue;
        }
    }
    int temp = (int)num.size();
    if(temp!=len) cout<<"-1\n";
    else{
    sort(num.begin(),num.end());
    
    int choke; string str="";
    for(int i=0;i<(int)num.size();i++) if(num[i]>0) { choke=i; break; }
    swap(num[0],num[choke]);
    for(int i=0;i<(int)num.size();i++){
        str+=(num[i]+'0');
    }
    cout<<str<<endl; 
    
 
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} }
=======
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    map<string,int> m;
    for(int i=0;i<s1.length();i++){
        for(int j=1;j+i<=s1.length();j++){
            string tmp = s1.substr(i,j);
            if(m[tmp]) continue;
            else{
                    m.insert(make_pair(tmp,0));
                    reverse(tmp.begin(),tmp.end());
                    m.insert(make_pair(tmp,1));
            }
        }
    }
    map<string,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<"  "<<it->second<<endl;
        it++;
    }
return 0;
}
>>>>>>> 3cb8da3ce56a7a80c4637270569219b9e1b45555
