class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto i: nums){
            s.insert(i);
        }
        for(int i = 1;i<=101;i++){
            if(s.find(i*k)==s.end()){
                return i*k;
            }
        }
        return -1;
    }
};