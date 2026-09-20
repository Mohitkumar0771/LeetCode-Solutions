class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedVals;
        inorder(root, sortedVals);
        return buildBalancedBST(sortedVals, 0, sortedVals.size() - 1);
    }

private:
    void inorder(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    TreeNode* buildBalancedBST(const vector<int>& vals, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(vals[mid]);

        node->left = buildBalancedBST(vals, left, mid - 1);
        node->right = buildBalancedBST(vals, mid + 1, right);

        return node;
    }
};