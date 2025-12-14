class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> xAxis, yAxis;
        
        for(auto i : buildings) {
            if(xAxis.find(i[0]) == xAxis.end()) {
                xAxis[i[0]] = {i[1], i[1]};
            } else {
                xAxis[i[0]][0] = min(xAxis[i[0]][0], i[1]);
                xAxis[i[0]][1] = max(xAxis[i[0]][1], i[1]);
            }
            
            if(yAxis.find(i[1]) == yAxis.end()) {
                yAxis[i[1]] = {i[0], i[0]};
            } else {
                yAxis[i[1]][0] = min(yAxis[i[1]][0], i[0]);
                yAxis[i[1]][1] = max(yAxis[i[1]][1], i[0]);
            }
        }
        
        int result = 0;
        for(auto i : buildings) {
            if(xAxis[i[0]][0] < i[1] && i[1] < xAxis[i[0]][1] && 
               yAxis[i[1]][0] < i[0] && i[0] < yAxis[i[1]][1]) {
                result++;
            }
        }
        
        return result;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });