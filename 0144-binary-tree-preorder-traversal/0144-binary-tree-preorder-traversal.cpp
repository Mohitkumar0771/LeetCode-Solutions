class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                // If there is no left child, visit this node and go right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the in-order predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    // Create thread and visit node before traversing left subtree
                    pred->right = curr;
                    result.push_back(curr->val);
                    curr = curr->left;
                } else {
                    // Thread already exists: remove it and traverse right
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};