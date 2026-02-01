class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first  = nums[0];
        sort(nums.begin(), nums.end());
        if(first != nums[0] && first!=nums[1])
        return nums[0]+nums[1]+first;
        else return nums[0]+nums[1]+nums[2];
    }
};