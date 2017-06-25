#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
vector<int> primes;

void seive(int N)
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=false;
    primes.push_back(2);
    for(int i = 4; i < N; i+= 2) prime[i]=false;
     
    for(int i = 3; i*i < N;i+= 2)
    if(prime[i]){
    	primes.push_back(i);
        for(int j = i*i; j < N; j+= (i<<1))
            prime[j]=false;
    }
}

bool product(int temp){
	for(int i=0;primes[i]*primes[i]<=temp;i++)
		if(prime[temp/primes[i]]) return true;
	return false;
}

bool cyanide(int x,int arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[i]!=0){
			int temp = x;
			while(temp%arr[i]==0){
				temp/=arr[i];
				if(product(temp)) return true;
			}
		}
	}
	return false;
}

int main(){
	
	int n,q; cin>>n>>q; 
	int arr[n]; seive(1000001);
	for(int i=0;i<n;i++) cin>>arr[i];
	while(q--){
		int x; cin>>x;
		if(cyanide(x,arr,n)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}