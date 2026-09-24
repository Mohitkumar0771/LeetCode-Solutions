class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

private:
    bool validate(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (!node) return true;

        if ((low && node->val <= low->val) || (high && node->val >= high->val)) {
            return false;
        }

        return validate(node->left, low, node) && 
               validate(node->right, node, high);
    }
};