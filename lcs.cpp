// finding the lcs of two string, it means finding the longest common sequence of characters, not working some issue with string parameter

#include <bits/stdc++.h>
#include <cstring> 
int lcs(string str1,string str2,int len1,int len2){
	
	int dp[len1+1][len2+1];
	
	for(int i=0;i<=len1;i++){
		for(int j=0;j<=len2;j++)
			if(i==0 or j==0) dp[i][j]=0;
			if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
	}
	return dp[len][len2];
}

int main(){
	
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	int len1 = str1.length();
	int len2 = str2.length();
	cout<<lcs(str1,str2,len1,len2)<<endl;

	return 0;
}