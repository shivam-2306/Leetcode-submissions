class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int> > m;
        int j = 0;
        for(auto i:arr){
            m[i].push_back(j);
            j++;
        }
        j = 1;
        for(auto i = m.begin();i!=m.end();i++){
            for(auto k:i->second){
                arr[k] = j;
            }j++;
        }
        return arr;
    }
};