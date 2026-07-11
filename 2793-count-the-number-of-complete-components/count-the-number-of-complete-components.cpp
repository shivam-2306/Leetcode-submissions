class Solution {
public:
    int res = 0;
    void traverser(int num, vector<vector<int>>& adjacencyList,
                   vector<int>& visited, bool begin) {
        if (adjacencyList[num].size() == 0){
            res++;return;}
        if (begin) {
            bool trace = false;
            visited[num] = 1;
            for (auto i : adjacencyList[num]) {
                visited[i] = 1;
            }
            for (auto i : adjacencyList[num]) {
                if(adjacencyList[num].size() != adjacencyList[i].size()){
                    trace = true;
                }
                for (auto j : adjacencyList[i]) {
                    if (visited[j] == 0) {
                        visited[j] = 1;
                        trace = true;
                        traverser(j, adjacencyList, visited, false);
                    }
                }
            }
            if (!trace)
                res++;
        }
        for (auto i : adjacencyList[num]) {
            if (visited[i] == 0) {
                visited[i] = 1;
                traverser(i, adjacencyList, visited, false);
            }
        }
    }
    // return true;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        for (auto i : edges) {
            adjacencyList[i[0]].push_back(i[1]);
            adjacencyList[i[1]].push_back(i[0]);
        }
        vector<int> visited(n, 0);
        int temp = 0;
        // for (auto i : adjacencyList) {
        //     cout << temp << "====>  ";
        //     temp++;
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n\n\n";
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                // cout << i << "\n";
                traverser(i, adjacencyList, visited, true);
                // if (connected) {
                //     cout << "   Found\n";
                //     res++;
                // }
            }
        }
        return res;
    }
};