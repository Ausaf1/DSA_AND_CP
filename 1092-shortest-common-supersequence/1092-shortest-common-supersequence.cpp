class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length(),n2 = str2.length();
        vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));
        for(int i = 1;i <= n1;i++){
            for(int j = 1;j <= n2;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        string ans = "";
        int i = n1,j = n2;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans = str1[i-1] + ans;
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans = str1[i-1] + ans;
                i--; 
            }
            else{
                ans = str2[j-1] + ans;
                j--;
            }
        }
        while(i > 0) ans = str1[i-1] + ans,i--;
        while(j > 0) ans = str2[j-1] + ans,j--;
        return ans;
    }
};