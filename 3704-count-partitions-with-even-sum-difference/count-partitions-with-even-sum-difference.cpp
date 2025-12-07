class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for(auto i:nums){
            totalSum += i;
        }
        int result = 0;
        int prefixSum = 0;
        for(int i = 0;i<nums.size()-1;i++){

            prefixSum += nums[i];
            if((2*prefixSum - totalSum)%2 == 0)result++; 
        }
        return result;
    }
};