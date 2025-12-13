class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        auto isAlphanumericAndUnderscore = [](string s) {
            regex pattern("^[a-zA-Z0-9_]+$");
            return regex_match(s, pattern);
        };
        unordered_set<string> c = {"electronics", "grocery", "pharmacy", "restaurant"};
        map<string, vector<string>> categories;
        categories["electronics"] = vector<string>();
        categories["grocery"] = vector<string>();
        categories["pharmacy"] = vector<string>();
        categories["restaurant"] = vector<string>();
        for(int i = 0;i<isActive.size();i++){
            if(isActive[i] && code[i].size() && isAlphanumericAndUnderscore(code[i]) && c.find(businessLine[i]) != c.end()){
               categories[businessLine[i]].push_back(code[i]); 
            }
        }
        vector<string> result;
        for(auto i = categories.begin() ; i != categories.end(); i++){
            sort(i->second.begin(), i->second.end());
            for(auto j: i->second){
                
                result.push_back(j);
            }
        }
        return result;
    }
};