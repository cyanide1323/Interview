// ones to be flipped 

#include<bits/stdc++.h>
using namespace std;

int solution(string str,int m){
	int len = str.length();
	int wl=0,wr=0,zc=0,l=0,val=INT_MIN;
	while(wr<len){
		
		if(zc<=m){
			if(str[wr]=='0')
				zc++;
		wr++;
		}

		if(zc>m){
			if(str[wl]=='0')
				zc--;
		wl++;
		}

		if(wr-wl>val)
			val=max(val,(wr-wl)),l=wl;
	}
	for(int i=0;i<wr-wl;i++)
		cout<<l+i<<" ";
	cout<<endl;
	return val;
}

int main(){
	
	string str; cin>>str;
	int m; cin>>m;
	cout<<"Answer is "<<solution(str,m)<<endl;
	return 0;
}