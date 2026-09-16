class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorder(TreeNode* node, int& prev, int& minDiff) {
        if (!node) return;

        inorder(node->left, prev, minDiff);

        if (prev != -1) {
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;

        inorder(node->right, prev, minDiff);
    }
};