#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
 
// To store segment tree
long *st;
 
/*
long gcd(long a, long b)
{
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return gcd(b, a%b);
}*/

template<class T>
T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
 
long findGcd(long ss, long se, long qs, long qe, long si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    long mid = ss+(se-ss)/2;
    return gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}
 

long findRangeGcd(long i, long j, long arr[],long n)
{
    if (i<0 || j > n-1 || i>j)
        return -1;
    
    return findGcd(0, n-1, i, j, 0);
}
 

long constructST(long arr[], long i, long j, long k)
{
    if (i==j)
    {
        st[k] = arr[i];
        return st[k];
    }
    long mid = i+(j-i)/2;
    st[k] = gcd(constructST(arr, i, mid, k*2+1),
                 constructST(arr, mid+1, j, k*2+2));
    return st[k];
}
 

long *constructSegmentTree(long arr[], long n)
{
   long height = (long)(ceil(log2(n)));
   long size = 2*(long)pow(2, height)-1;
   st = new long[size];
   constructST(arr, 0, n-1, 0);
   return st;
}

void multiply(long F[2][2], long M[2][2]);
 
void power(long F[2][2], long n);
 
/* function that returns nth Fibonacci number */
long fib(long n)
{
  long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 

void power(long F[2][2], long n)
{
  if( n == 0 || n == 1)
      return;
  long M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long F[2][2], long M[2][2])
{
  long x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
  long y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
  long z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
  long w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 

int main()
{
    long n,q; cin>>n>>q; 
    long arr[n];
    for(long i=0;i<n;i++) cin>>arr[i];
   
    constructSegmentTree(arr, n);

    
    while(q--){
        long l,r; 
        cin>>l>>r;
        long val = findRangeGcd(l-1,r-1,arr,n);
        
        cout<<fib(val)<<endl;
    }
 
    return 0;
}