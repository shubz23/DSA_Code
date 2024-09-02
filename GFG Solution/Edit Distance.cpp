class Solution {
  public: 
    int editDistance(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    // If str1 is empty, insert all characters of str2
                    dp[i][j] = j;
                } else if (j == 0) {
                    // If str2 is empty, remove all characters of str1
                    dp[i][j] = i;
                } else if (str1[i - 1] == str2[j - 1]) {
                    // If last characters are the same, ignore them and recur for the remaining strings
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // If last characters are different, consider all possibilities and find the minimum
                    dp[i][j] = 1 + min({ dp[i - 1][j],     // Remove
                                         dp[i][j - 1],     // Insert
                                         dp[i - 1][j - 1]  // Replace
                                       });
                }
            }
        }

        return dp[m][n];
    }
};