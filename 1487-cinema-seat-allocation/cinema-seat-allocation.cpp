#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 5) reservedMap[row] |= 1;
            if (col >= 4 && col <= 7) reservedMap[row] |= 2;
            if (col >= 6 && col <= 9) reservedMap[row] |= 4;
        }
        
        int maxFamilies = (n - reservedMap.size()) * 2;
        
        for (const auto& [row, mask] : reservedMap) {
            
            if ((mask & 1) == 0 && (mask & 4) == 0) {
                maxFamilies += 2;
            } 
            else if ((mask & 1) == 0 || (mask & 2) == 0 || (mask & 4) == 0) {
                maxFamilies += 1;
            }
        }
        
        return maxFamilies;
    }
};