class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [min_ptr, max_ptr] = minmax_element(nums.begin(), nums.end());
        vector<int> arr(*max_ptr-*min_ptr+1, 0);
        for(auto i: nums){
            arr[i-*min_ptr]++;
        }
        vector<int> res;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == 0){
                res.push_back(i+*min_ptr);
            }
        }
        return res;
    }
};