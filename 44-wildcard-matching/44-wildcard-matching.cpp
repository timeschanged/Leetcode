class Solution {
public:
    bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0) {
            for(; i>=0; i--) {
                if(s[i] != '*') return false;
            }
            return true;
        } 
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j] || s[i] == '?') return dp[i][j] = f(i-1, j-1, s, t, dp);
        else if(s[i] == '*') return dp[i][j] = f(i-1, j, s, t, dp) || f(i, j-1, s, t, dp);
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return f(m-1, n-1, p, s, dp);
    }
};