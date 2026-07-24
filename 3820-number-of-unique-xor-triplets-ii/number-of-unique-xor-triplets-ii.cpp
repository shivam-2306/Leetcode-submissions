class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int MAXX = 2049;
        vector<int> pairXorr(MAXX, 0);
        vector<int> ansXorr(MAXX, 0);
        for(int i = 0;i<nums.size();i++){
            for(int j = i;j<nums.size();j++){
                pairXorr[nums[i]^nums[j]] = true;
            }
        }

        for(int i = 0;i<MAXX;i++){
            if(pairXorr[i]){
                for(auto j:nums){

                ansXorr[i^j] = 1;
                }
            }
        }
        int res = 0;
        for(auto i : ansXorr){
            res+=i;
        }
        return res;
    }
};