class Solution {
public:
    int helper(int start,int end,vector<vector<int>> &dp){
        if(start >= end)
            return 1;
        if(dp[start][end] != -1)
            return dp[start][end];
        int ans = 0;
        for(int i = start;i <= end;i++){
            int left = helper(start,i - 1,dp);
            int right = helper(i + 1,end,dp);
            ans += left*right;
        }
        return dp[start][end] = ans;
    }
    
    int numTrees(int n) {
        vector<vector<int>> dp(20,vector<int>(20,-1));
        int ans = helper(1,n,dp);
        return ans;
    }
};