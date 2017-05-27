// sorting an array according to format of different array

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<int,int> mymap;

void sortedHashMap(int arr1[],int arr2[],int m,int n){
	
	sort(arr1,arr1+m);
	for(int i=0;i<m;i++){
		if(mymap.find(arr1[i])!=mymap.end()) mymap[arr1[i]]++;
		else mymap.insert(make_pair(arr1[i],1));
	}


	map<int,int>::iterator it = mymap.begin();


	int index=0,j;
	for(int i=0;i<n;i++){
		if(mymap.find(arr2[i])!=mymap.end()){
			int count = mymap[arr2[i]];
			for(j=0;j<count;j++)
				arr1[j+index]=arr2[i];
			index+=j;
			mymap.erase(arr2[i]);
		}
	}

	it=mymap.begin();

	while(it!=mymap.end()){
		for(j=0;j<it->second;j++)
			arr1[j+index]=it->first;
		index+=j;
		it++;
	}
	for(int i=0;i<m;i++) 
		cout<<arr1[i]<<"  ";
	cout<<endl;
}	

bool compare(int a,int b){
	
	int index=-1, index2=-1;

	index1 = search(arr2,a);
	index2 = search(arr2,b);

	if(index1==-1 and index2==-1) 
		return a<=b;
	if(index1!=-1 and index2!=-1)
		return index1<index2;
	

}

int main(){
	int arr1[]={2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
	int arr2[]={2, 1, 8, 3};
	int output[]={2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9};
	int m=11,n=4;
	sortedHashMap(arr1,arr2,m,n);
	sort(arr1,arr1+m,compare);
	cout<<"--------------------------------------------------------------\n";
	for(int i=0;i<m;i++) cout<<arr1[i]<<"  ";
	cout<<endl;
	return 0;
}