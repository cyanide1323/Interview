#include <bits/stdc++.h>
using namespace std;

void sp(int *a,int *b){
    int temp = *a;
    *b = *a;
    *a = temp;
}

void shuffle(int arr[],int n){
    for(int i=n-1;i>0;i--){
        int id = rand()%i;
        sp(&arr[id],&arr[i]);
    }
    return;
}

int main(){

    int n; cin>>n; int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
    cout<<endl;
    shuffle(arr,5);

    return 0;
}
