// Time Complexity: O(N*W)
// Space Complexity: O(N*W)

#include<bits/stdc++.h>
int solve(vector<int> &values, vector<int> &weights,int w, int i,vector<vector<int>>&dp){
	if(i>=values.size())
		return 0;

	if(dp[i][w]!=-1)
		return dp[i][w];

	int notTake= 0+solve(values, weights, w, i+1, dp);
	int take= 0;
	if(w>=weights[i])
		take=values[i] +solve(values, weights, w-weights[i], i+1, dp);

	return dp[i][w]=max(take,notTake);

}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	return solve(values, weights, w, 0, dp);

}