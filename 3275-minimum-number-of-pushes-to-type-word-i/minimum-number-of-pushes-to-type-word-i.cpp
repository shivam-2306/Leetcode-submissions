class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequencyMap(26, 0);
        for(auto i:word){
            frequencyMap[i-'a']++;
        }
        sort(frequencyMap.begin(), frequencyMap.end());
        int covered = 0;
        int res = 0;
        for(auto i: frequencyMap){
            cout<<i<<" ";
        }
        for (int j = 25;j>=0;j--){
            if(frequencyMap[j] == 0) break;
            if(covered < 8){
                res += frequencyMap[j];
                covered++;
            }
            else if(covered >= 8 && covered < 16){
                res += frequencyMap[j]*2;
                covered++;
            }
            else if(covered>=16 && covered<24) {
                res+= frequencyMap[j]*3;
                covered++;
            }
            else {
                res += frequencyMap[j]*4;
            }
        }
        return res;
    }
};