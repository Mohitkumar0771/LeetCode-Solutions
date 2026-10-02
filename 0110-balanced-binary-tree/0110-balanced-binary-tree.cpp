#include <algorithm>
#include <cstdlib>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftH = checkHeight(node->left);
        if (leftH == -1) return -1;

        int rightH = checkHeight(node->right);
        if (rightH == -1) return -1;

        if (std::abs(leftH - rightH) > 1) {
            return -1;
        }

        return 1 + std::max(leftH, rightH);
    }
};