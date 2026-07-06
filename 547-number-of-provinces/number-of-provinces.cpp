class Solution {
public:
    void traverser (vector<vector<int> > adjacencyList,vector<bool>& visited, int node ){
        visited[node] = true;
        for(auto i: adjacencyList[node]){
            if(visited[i] == false){
                traverser(adjacencyList, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int> > adjacencyList(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(visited[i] == false){
                res++;
                traverser(adjacencyList, visited, i);
            }
        }
        return res;
    }
};