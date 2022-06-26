// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1/

int dp[100000];
int solve(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	else
	{
		return dp[n] = (solve(n - 10) + solve(n - 3) + solve(n - 5));
	}
}

long long int count(long long int n)
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	return solve(n);
}