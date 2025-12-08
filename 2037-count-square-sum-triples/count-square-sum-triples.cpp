class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        unordered_set<int> s;
        for(int i = 1;i<=n;i++){
            s.insert(i*i);
        }
        for(int i = 1;i<=n;i++){
            for(int j = i;j<=n;j++){
                int temp = i*i + j*j;
                if(s.find(temp) != s.end()) i == j?result++:result+=2;
            }
        }
        return result;
    }
};