#include <iostream>
using namespace std;

void rotat(int arr[][4],int m,int n){

    int i=0,j=0,start_row=0,start_col=0;

    while(j<n){
        cout<<arr[start_row][j]<<" ";
        j++;
    }

    start_row++;


    while(i<m){
        cout<<arr[i][j]<<" ";
        i++;
    }

    n--;

    while(j>=start_col){
        cout<<arr[i][j]<<" ";
        j--;
    }

    m--;

    while(i>=start_row){
        cout<<arr[i][j]<<" ";
        i--;
    }

    start_row++;
}

int main(){

    int m,n; cin>>m>>n; int arr[m][n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    rotat(arr,m,n);

    return 0;
}
