#include <bits/stdc++.h>
int solve(int i,int j,string s,string t,vector<vector<int>>&dp){
	if(i<0||j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(s[i]==t[j]){
		return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
	}
	return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
}
int lcs(string s, string t)
{
	//Write your code here
	int n=s.size();
	int m=t.size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	int ans=solve(n-1,m-1,s,t,dp);
	string st;
	int i=n-1,j=m-1;
	while(i>=0&&j>=0){
		if(s[i]==t[j]){
			st.push_back(s[i]);
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])i--;
		else j--;
	}
	reverse(st.begin(),st.end());
	cout<<st<<endl;
	return ans;
}
