#include<bits/stdc++.h>
using namespace std;

int profit[] = {15, 25, 13, 23};
int weight[] = {2, 6, 12, 9};

int knapsack01_MemoDP(int W, int n, vector<vector<int>>& dp)
{
    // Base case
    if(n == 0 || W == 0)
        return 0;

    // Already calculated
    if(dp[n][W] != -1)
        return dp[n][W];

    int val = profit[n-1];
    int wt = weight[n-1];

    // If current item can be included
    if(wt <= W)
    {
        int include = val + knapsack01_MemoDP(W-wt, n-1, dp);

        int exclude = knapsack01_MemoDP(W, n-1, dp);

        return dp[n][W] = max(include, exclude);
    }

    // If current item cannot be included
    else
    {
        return dp[n][W] = knapsack01_MemoDP(W, n-1, dp);
    }
}

int main()
{
    int n = 4;
    int W = 20;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    int answer = knapsack01_MemoDP(W, n, dp);

    cout << "Maximum Profit = " << answer << endl;

    return 0;
}