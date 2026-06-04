class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        vector<int> freq(100001, 0);

        for (int x : asteroids)
            freq[x]++;

        long long currMass = mass;

        for (int i = 1; i <= 100000; i++) {
            if (freq[i] == 0) continue;

            if (currMass < i)
                return false;

            currMass += 1LL * freq[i] * i;
        }

        return true;
    }
};