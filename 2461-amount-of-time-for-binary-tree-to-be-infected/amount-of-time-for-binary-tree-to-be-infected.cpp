class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;

        // Build parent pointers and find start node
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                startNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS from start
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);

        int time = -1;

        while (!q.empty()) {
            int sz = q.size();
            time++;

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                // Left
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                // Right
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                // Parent
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        return time;
    }
};