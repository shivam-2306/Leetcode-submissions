class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> bada(26,0), chhota(26, 0);
        for(auto i: word){
            int ind = i - 'a';
            if(ind>=0 && ind<26)
            chhota[ind]++;
            else bada[i-'A']++;
        }
        int res = 0;
        for(int i = 0;i<26;i++){
            if(chhota[i] && bada[i])res++;
        }
        return res;
    }
};