class Solution {
public:
    int solve(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        int take=0,left=0,right=0;

        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]){
            take = 1+solve(i-1,j-1,text1,text2,dp);
        }else{
            left = solve(i-1,j,text1,text2,dp);
            right = solve(i,j-1,text1,text2,dp);
        }
        return dp[i][j] = max(take,max(left,right));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n,(vector<int>(m,-1)));

        return solve(n-1,m-1,text1,text2,dp);
    }
};
