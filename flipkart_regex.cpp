// regex question of flipkart 
// question link : http://www.geeksforgeeks.org/flipkart-interview-set-4-sde-1/

// flipkart question 

// applying djikstras's alogirthm implemented before

// lru cache design in cpp

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

// Definitions of the regex 

1. Normal alphabets – a to z and A to Z
2. ‘$’ – all string should end with all characters preceding $
Example:
Regex :abc$ ,
Pattern: abcd(Not acceptable) , abc(acceptable), ab(Not acceptable), dhfusdhabc(acceptable) etc..
3. ‘^’ – all string should start with all characters exceeding ^
Example: Regex : ^abc
Pattern: abcd(acceptable) , abc(acceptable), ab(Not acceptable), dhfusdhabc(NOT acceptable) etc..
Regex: ^ then only pattern acceptable is null.
4. ‘.’ – any character can be mapped to dot except null
Example 1: Regex : .abc
Pattern: Zabc(acceptable) , abc(NOT acceptable), ab(Not acceptable), habc(acceptable) etc..
Example 2: Regex :a.bc
Pattern: abc(NOT acceptable) , aXbc(acceptable), ab(Not acceptable), habc(NOT acceptable) etc..
5. ‘*’-the character just preceding * can be repeated n time where (n>=0)
Example 1: Regex :abc*de
Pattern: abccccccccccde (acceptable), abcde(acceptable), abcccd(not acceptable)
*/

class Match{
	string pattern, regex;
	public:
		void setPattern(string pattern);
		void setRegex(string regex);
		string getPattern();
		string getRegex();
		bool check();
};

void Match::setPattern(string patternn){
	this.pattern = pattern;
}

void Match::setRegex(string regex){
	this.regex = regex;
}

string Match::getPattern(){
	return pattern;
}

string Match::getRegex(){
	return regex;
}

bool Match::check(){

}

int main(int argc,char *argv[]){

    //clock_t startTime = clock();
	Match match;
	string pattern, regex; 
	
	cin >> regex; getchar(); 
	match.setRegex(regex);
	
	int len; cin >> len;
	while(len--){
		cin >> pattern; 
		match.setPattern(pattern);
		if(match.check()) cout << "Pattern is compatible\n";
		else cout << "Pattern is not compatible\n";
	}
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}  