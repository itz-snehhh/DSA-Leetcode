class Solution {
public:
    int LIS(int i, int prev, vector<int>&nums,vector<vector<int>> & dp){

        if(i == nums.size()){
            return 0;
        }
        if(dp[i][prev+1] !=-1) return dp[i][prev+1];
        int notTake = LIS(i+1, prev, nums, dp);

        int take =0;
        if(prev ==-1 || nums[prev] < nums[i]){
            take = 1 + LIS(i+1, i, nums, dp);
        }
        return dp[i][prev+1] = max(take,  notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        //top down
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(0, -1, nums, dp);


    }
};