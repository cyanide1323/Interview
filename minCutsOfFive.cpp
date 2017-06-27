// cpp code to find the string if it can be represented int the form of powers of 5

#include <bits/stdc++.h>
using namespace std;

int minCuts(string str,int pos,int len){
	
	if(pos == len or isPowerofFive(str))
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	long long value = 0;
	int ans = MAX_INT;
	for(int i=pos;i<len;i++){
		value = value*2 + (str[i]-'0');
		if(isPowerofFive(value))
			ans = min(ans,minCuts(str.substr(i+1),pos+1,len));
	}
	return dp[pos]=ans;
}

bool cyanide(string str,int pos, int len){
	int len = (int)str.length();
	int dp[len]; memset(dp,-1,sizeof(dp));
	int ans = minCuts(str,0,len);
}

int main(){

	string str;
	getline(cin,str);
	bool flag = cyanide(str);
	if(flag) printf("Yes this can be done\n");
	else printf("No it cannot be done\n");

	return 0;
}