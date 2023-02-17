class Solution {
public:
    int lis(int n, vector<int> &a, vector<int> &dp) {
        if(dp[n] != -1) return dp[n];
        int ans = 1;
        for(int i=0; i<n; i++){
            if(a[i]<a[n]) 
                ans = max(ans, lis(i, a, dp) + 1);
        }
        return dp[n] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n, -1);
        for(int i = 0; i<n; i++){
            ans = max(ans, lis(i, nums, dp));
        }
        return ans;
    }
};