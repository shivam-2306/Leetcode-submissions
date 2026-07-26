class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto i: nums){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        return (long long)(maxi-mini)*k;
    }
};