class Solution {
  public:
    int nthFibonacci(int n){
        const int MOD = 1000000007;
        
        if(n==1 || n==2){
            return 1;
        }
        
        vector<int> dp(n+1,0);
        dp[1] =1;
        dp[2] = 1;
        
        
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            
        }
        return dp[n];
    }
};