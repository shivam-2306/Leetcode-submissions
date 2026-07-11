class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = 0;
        for(auto i :candies){
            maxNum = max(maxNum, i);
        }
        vector<bool> ans;
        for(auto i: candies){
            (i+extraCandies >= maxNum)? ans.push_back(true): ans.push_back(false);
        }
        return ans;
    }
};