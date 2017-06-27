#include <bits/stdc++.h>
using namespace std;
const int n=4; 
bool isSafe(bool arr[n][n],int row,int col){

	for(int i=0;i<col;i++){
		if(arr[row][i])
			return false;
	}

	int a = row, b = col;
	while(a>=0 and b>=0){
		if(arr[a][b])
			return false;
		a--;
		b--;
	}

	a=row; b = col;
	while(a<n and b>=0){
		if(arr[a][b])
			return false;
		a++;
		b--;
	}
	return true;
}

bool solve(bool arr[n][n],int row,int col){
	if(col>=n)
		return true;
	for(int i=0;i<n;i++){
		if(isSafe(arr,i,col)){
			arr[i][col]=1;
			if(solve(arr,row,col+1))
				return true;
			arr[i][col]=0;
		}
	}
	return false;
}

 void printSolution(bool arr[n][n]){
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			cout<<arr[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 }

int main(){
	bool arr[n][n];
	memset(arr,0,sizeof(arr));
	if(solve(arr,0,0))
		printSolution(arr);
	else 
		cout<<"queens cannot be placed\n";
	return 0;
}