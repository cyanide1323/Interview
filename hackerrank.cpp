#include <bits/stdc++.h>
using namespace std;

int convert(string temp){
	int num = 0;
	for(int i=0;i<temp.length();i++){
		char ch = temp[i];
		int val = ch-'0';
		num*=10;
		num+=val;
	}
	return num;
}

void cyanide(string str){
	
	int cnt[27];
	memset(cnt,0,sizeof(cnt));

	int len = (int)str.length();
	int pos = 0;
	while(pos<len){
		if(pos+2<len and str[pos+2]!='#'){
			string temp = "";
			temp+=str[pos];
			pos++;
			int value = convert(temp);
			if(pos<len and str[pos]=='('){
				pos++; string var = "";
				while(str[pos]!=')'){
					var+=str[pos];
					pos++;
				}
				int temp = convert(var);
				cnt[value]+=temp;
			}		
			else 
				cnt[value]++;
		}
		else{
			string temp = "";
			temp+=str[pos];
			temp+=str[pos+1];
			pos+=3;
			int value = convert(temp);
			if(pos<len and str[pos]=='('){
				pos++; string var = "";
				while(str[pos]!=')'){
					var+=str[pos];
					pos++;
				}
				int temp = convert(var);
				cnt[value]+=temp;
			}
			else 
				cnt[value]++;
		}
	}
	for(int i=1;i<=26;i++){
		cout<<i<<" --> "<<cnt[i]<<endl;
	}
}

int main(){
	int tc; cin>>tc; getchar();
	while(tc--){
		string str; 
		cin>>str;
		cyanide(str);
		cout<<"\n\n\n"<<endl;
	}
	return 0;
}