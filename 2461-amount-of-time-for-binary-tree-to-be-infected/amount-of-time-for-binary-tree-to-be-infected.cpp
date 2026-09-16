class Solution {
public:
    int startVal = 0;
    TreeNode* start = nullptr;

    void adjMaker(unordered_map<TreeNode*, vector<TreeNode*>>& adj,
                  TreeNode* root) {

        if (root == nullptr)
            return;

        if (root->val == startVal) {
            start = root;
        }

        if (root->left != nullptr) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }

        if (root->right != nullptr) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }

        adjMaker(adj, root->left);
        adjMaker(adj, root->right);
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> visited;

        startVal = start;

        adjMaker(adj, root);

        queue<TreeNode*> q;

        q.push(this->start);
        q.push(nullptr); // END OF LEVEL

        visited.insert(this->start);

        int res = -1;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == nullptr) {
                res++;
                if (!q.empty()) {
                    q.push(nullptr);
                }
                continue;
            }
            for (TreeNode* node : adj[temp]) {

                if (visited.find(node) != visited.end())
                    continue;

                visited.insert(node);
                q.push(node);
            }
        }

        return res;
    }
};