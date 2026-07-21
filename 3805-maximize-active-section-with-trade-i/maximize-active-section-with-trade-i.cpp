class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int, char> > res;
        char curr = 'a';
        int currCount = 1;
        for(auto i: s){
            if(curr == 'a'){
                curr = i;
            }
            else if(curr != i){
                res.push_back({currCount, curr});
                curr = i;
                currCount = 1;
            }
            else {
                currCount++;
            }
        }
        res.push_back({currCount, curr });
        int addition = 0;
        int result = 0;
        for(int i = 0;i<res.size();i++){
            if(res[i].second == '1'){
                result += res[i].first;
                if(i == 0 || i == res.size()-1)continue;
                int temp = res[i-1].first;
                temp += res[i+1].first;
                addition = max(temp, addition);
            }
        }
        cout<<result<<" "<<addition;
        return result+addition;
    }
};