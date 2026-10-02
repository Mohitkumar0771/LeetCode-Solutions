#include <queue>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (!curr->left && !curr->right) {
                    return depth;
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            depth++;
        }

        return depth;
    }
};