class Solution {
public:
    int m= 0, n = 0;
    bool valid(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    void traverser(vector<vector<int>>& grid, vector<vector<int>>& healthMap, int health, int i , int j){
        if(!valid(i,j)) return;
        if(i == m-1 && n == n-1){
            healthMap[i][j] = max(healthMap[i][j], health-grid[i][j]);
            return;
        }
        if(healthMap[i][j] >= health - grid[i][j]) return;
        healthMap[i][j] = health - grid[i][j];
        if(healthMap[i][j] == 0) return;
        traverser(grid, healthMap,healthMap[i][j], i+1,j);
        traverser(grid, healthMap,healthMap[i][j], i-1,j);
        traverser(grid, healthMap,healthMap[i][j], i,j-1);
        traverser(grid, healthMap,healthMap[i][j], i,j+1);
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();n = grid[0].size();
        vector<vector<int>> healthMap(m, vector<int>(n, 0));
        traverser(grid, healthMap, health, 0, 0);
        // for(auto i:grid){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }cout<<"\n";
        // }cout<<"\n\n\n\n";
        // for(auto i:healthMap){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }cout<<"\n";
        // }
        return healthMap[m-1][n-1] >= 1;
    }
};

















