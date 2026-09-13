/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            result.push_back(curr->val);

            // Push left first so right is processed first
            if (curr->left) {
                st.push(curr->left);
            }
            if (curr->right) {
                st.push(curr->right);
            }
        }

        // Reverse to convert Root -> Right -> Left into Left -> Right -> Root
        reverse(result.begin(), result.end());
        return result;
    }
};