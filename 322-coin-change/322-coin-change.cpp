class Solution {
public:
    int func(int amount, vector<int> &coins, vector<int> &dp) {
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(auto coin: coins)
            if(amount-coin >= 0) 
                ans = min(ans + 0ll, func(amount-coin, coins, dp) + 1ll);
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans = func(amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};