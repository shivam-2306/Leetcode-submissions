class Solution {
public:
    void addString(int a,int charNum, string& res){
        for(int i = 0;i<a;i++){
            res += charNum+'a';
        }
    }
    string smallestPalindrome(string s) {
        vector<int> frequencyMap(26, 0);
        for(auto i: s){
            frequencyMap[i-'a']++;
        }
        char temp = '\0';
        string res = "";
        for(int i = 0;i<26;i++){
            addString(frequencyMap[i]/2, i, res);
            if(frequencyMap[i]%2)
            temp = i+'a';
            // frequencyMap[i]++;
            frequencyMap[i]/=2;
        }
        if(temp-'a'>=0 && temp-'a'<=25)
        res += temp;
        // cout<<temp;
        // for(auto i: frequencyMap){
        //     cout<<i<<" ";
        // }
        for(int i = 25;i>=0;i--){
            addString(frequencyMap[i], i, res);
        }
        return res;
    }
};