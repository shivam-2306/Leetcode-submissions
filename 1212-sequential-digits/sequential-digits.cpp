class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        unordered_set<int> s;
        vector<int> res;
        for(int j = 0;j<9;j++){
            int temp = arr[j];
            for(int i = j+1;i<9;i++){
                temp *= 10;
                temp += arr[i];
                if(temp>=low && high>= temp){
                    res.push_back(temp);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};