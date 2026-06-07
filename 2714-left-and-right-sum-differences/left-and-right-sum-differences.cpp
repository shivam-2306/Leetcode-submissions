class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();
        vector<int> right(size,0);
        for(int i = size-2;i>=0;i--){
            right[i] = right[i+1] + nums[i+1];
        }
        int left = nums[0];
        for(int i = 1;i<size-1;i++){
            right[i] = abs(right[i] - left);
            left+=nums[i];
        }
        if(size!=1)
        right[size-1] = left;
        return right;
    }
};