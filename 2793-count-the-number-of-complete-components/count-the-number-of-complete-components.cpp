#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        // Step 2: Traverse each component
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int degreeSum = 0;

                // BFS to explore the entire connected component
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    vertexCount++;
                    degreeSum += adj[curr].size(); // Add the degree of the current node

                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Step 3: Check if the component is complete
                // In a complete graph of V vertices, the sum of all degrees is V * (V - 1)
                if (degreeSum == vertexCount * (vertexCount - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};