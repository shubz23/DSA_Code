// 1st code
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= W; ++j) {

                if (wt[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {

                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
            }
        }
        
        return dp[n][W];
    }
};

//2nd Code

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        
        int N = wt.size();
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        
        // Build the dp table
        for (int i = 1; i <= N; ++i) {
            for (int w = 1; w <= W; ++w) {
                if (wt[i-1] <= w) {
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]);
                } else {
                    dp[i][w] = dp[i-1][w]; // If not including the item
                }
            }
        }
        
        return dp[N][W];
    }
};