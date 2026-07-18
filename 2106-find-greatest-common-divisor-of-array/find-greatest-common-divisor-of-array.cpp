class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for(auto i:nums){
            minimum = min(minimum, i);
            maximum = max(i, maximum);
        }
        while(minimum != 0){
            int temp = maximum%minimum;
            maximum = minimum;
            minimum = temp;
        }
        return maximum;
        
    }
};