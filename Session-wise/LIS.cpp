class Solution {
public:
    int solve(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0,notake = 0,pos = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1+solve(i+1,i,nums,dp);
            notake = solve(i+1,prev,nums,dp);
        }else{
            pos = solve(i+1,prev,nums,dp);
        }
        return dp[i][prev+1] = max(take,max(notake,pos));
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // int n = arr.size();
        for(int i = n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int len = 0 + dp[i+1][j+1];
                if(j == -1 || arr[i] > arr[j]){
                    len = max(len,1+dp[i+1][i+1]);
                }
                dp[i][j+1] = len;
            }
        }
        return dp[0][0]+1;
        // return solve(0,-1,nums,dp);
    }
};
