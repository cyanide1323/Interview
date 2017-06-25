// petrol pumps 

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

struct node{
	int petrol;
	int distance;
};

int FindIndex(node arr[],int n){

	int start = 0;
	int end = start+1;

	int petrol_reserve = arr[start].petrol-arr[start].distance;

	while(start!=end){

		while(petrol_reserve+arr[end].petrol<arr[end].distance){
			
			petrol_reserve-=(arr[start].petrol-arr[start].distance);
			start=(start+1)%n;

			if(start==0) return -1;
		}

		petrol_reserve += (arr[end].petrol-arr[end].distance);
		end = (end+1)%n;
	}
}

int FindIndex2(node arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		int current_reserve = arr[i].petrol-arr[i].distance;
		if(current_reserve<0) continue;
		j=(i+1)%n;
		while(current_reserve+arr[j].petrol>=arr[j].distance and ((j+1)%n)!=i){
			j=(j+1)%n;
		}
		if((j+1)%n==i) return i;
	}
	return -1;
}

int main(){
	int n; cin>>n; 
	node arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i].petrol>>arr[i].distance;

	cout<<"Index is "<<FindIndex(arr,n)<<endl;
	cout<<"Index from second is "<<FindIndex2(arr,n)<<endl;
	return 0;
}