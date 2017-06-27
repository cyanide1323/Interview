#include <bits/stdc++.h>
using namespace std;

int cyanide(int arr[],int n){
    stack<int> st; int area = 0,i=0;

    while(i<n){
      cout<<"i is "<<i<<endl;
      if(st.empty() or arr[st.top()]<=arr[i])
        st.push(i++);
      else{
          int tp = st.top();
          st.pop();
          int len = (st.empty())?i:(i-st.top()-1);
          area = max(area,arr[tp]*len);
      }
    }

    while(!st.empty()){
      int tp = st.top();
      st.pop(); int len = (st.empty()?i:(i-st.top()-1));
      area = max(area,arr[tp]*len);
    }

    return area;
}

int main(){
  int n; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<cyanide(arr,n)<<endl;
  return 0;
}
