class Solution {
public:
    int maximum(vector<int>& piles, int i, int j, vector<vector<int> >& dp){
        if(i == j){
            return piles[i];
        }
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        int sumRight = piles[i] - maximum(piles, i+1,j, dp);
        int sumLeft = piles[j] - maximum(piles, i, j-1, dp);
        return dp[i][j] = max(sumRight, sumLeft);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int> > dp(piles.size(), vector<int> (piles.size(), INT_MIN));
        int maxi = maximum(piles, 0, piles.size()-1, dp);
        return maxi>0;
    }
};