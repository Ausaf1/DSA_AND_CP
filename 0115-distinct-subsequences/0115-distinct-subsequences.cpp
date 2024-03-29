class Solution {
private:
    int f(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(s,t,i-1,j-1,dp) + f(s,t,i-1,j,dp);
        return dp[i][j] = f(s,t,i-1,j,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length(),m = t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s,t,n-1,m-1,dp);
    }
};