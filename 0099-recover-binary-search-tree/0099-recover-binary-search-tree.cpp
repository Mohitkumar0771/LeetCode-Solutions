class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        inorder(root, first, second, prev);

        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void inorder(TreeNode* curr, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!curr) return;

        inorder(curr->left, first, second, prev);

        if (prev && prev->val > curr->val) {
            if (!first) {
                first = prev;
            }
            second = curr;
        }
        prev = curr;

        inorder(curr->right, first, second, prev);
    }
};