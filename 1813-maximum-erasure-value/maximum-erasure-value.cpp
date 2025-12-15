class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        nums.push_back(nums[size-1]);
        unordered_map<int, int> m;
        long long resultCount  = INT_MIN, currCount = 0;
        int i = 0, j = 0;
        while(i<=j && j<size+1){
            if(m.find(nums[j]) == m.end()){
                // cout<< nums[j]<<endl;
                m[nums[j]] = j;
                currCount+= nums[j];
                j++;
            }
            else {
                // cout<<currCount<<endl;
                resultCount = max(resultCount, currCount);
                while(i<=m[nums[j]]){
                    currCount -= nums[i];
                    m.erase(nums[i]);
                    i++;
                }
                currCount+=nums[j];
                m[nums[j]] = j;
                j++;
            }
        }
        return resultCount;

    }
};