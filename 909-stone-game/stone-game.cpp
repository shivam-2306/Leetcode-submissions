class Solution {
public:
    int calculate(vector<int>& stoneValue, int i, int j, vector<vector<int> >& dp){
        if(i == j){
            return stoneValue[i];
        }
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }
        int sumRight = stoneValue[i] - calculate(stoneValue, i+1, j, dp);
        int sumLeft = stoneValue[j] - calculate(stoneValue, i, j-1, dp);
        return dp[i][j] = max(sumRight, sumLeft);
    }
    bool stoneGame(vector<int>& stoneValue) {
        vector<vector<int> > dp(stoneValue.size(), vector<int> (stoneValue.size(), INT_MIN));
        int maxi = calculate(stoneValue, 0, stoneValue.size()-1,dp );
        return maxi > 0;
    }
};