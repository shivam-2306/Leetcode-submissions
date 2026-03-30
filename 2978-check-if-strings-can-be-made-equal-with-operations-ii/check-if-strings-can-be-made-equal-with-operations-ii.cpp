class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> odd (26, 0), even (26, 0);
        for(int i = 0;i<s1.size();i++){
            if(i%2 == 0){
                odd[s1[i] - 'a']++;
            }
            else {
                even[s1[i] - 'a']++;
            }
        }
        
        for(int i = 0;i<s2.size();i++){
            if(i%2 == 0){
                odd[s2[i] - 'a']--;
            }
            else {
                even[s2[i] - 'a']--;
            }
        }
        for(auto i:odd){
            if(i != 0) return false;
        }
        for(auto i:even){
            if(i != 0) return false;
        }
        return true;
    }
};