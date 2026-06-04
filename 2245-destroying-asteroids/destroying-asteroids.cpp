class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        unsigned long long int m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto i: asteroids){
            if(m<i) return false;
            m+=i;
        }
        return true;
    }
};