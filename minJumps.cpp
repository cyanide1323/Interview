#include <bits/stdc++.h>
using namespace std;

int jumps(int arr[],int n){
	int dp[n];
	memset(dp,10000,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]!=INT_MAX and j+arr[j]>=i)
				dp[i]=min(dp[i],dp[j]+1);
		}
	}
	return dp[n-1];
}

int main(){

	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout << jumps(arr,n) << endl;

	return 0;
}