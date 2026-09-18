class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        TreeNode* prev = nullptr;
        int currentCount = 0;
        int maxCount = 0;

        inorder(root, prev, currentCount, maxCount, modes);
        return modes;
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, int& currentCount, int& maxCount, vector<int>& modes) {
        if (!node) return;

        inorder(node->left, prev, currentCount, maxCount, modes);

        if (prev != nullptr && node->val == prev->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes.clear();
            modes.push_back(node->val);
        } else if (currentCount == maxCount) {
            modes.push_back(node->val);
        }

        prev = node;

        inorder(node->right, prev, currentCount, maxCount, modes);
    }
};