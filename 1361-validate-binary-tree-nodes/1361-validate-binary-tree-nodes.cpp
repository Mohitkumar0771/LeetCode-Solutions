class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++inDegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++inDegree[rightChild[i]] > 1) return false;
            }
        }

        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        visited[root] = true;
        int visitedCount = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visitedCount++;

            int left = leftChild[curr];
            if (left != -1) {
                if (visited[left]) return false;
                visited[left] = true;
                q.push(left);
            }

            int right = rightChild[curr];
            if (right != -1) {
                if (visited[right]) return false;
                visited[right] = true;
                q.push(right);
            }
        }

        return visitedCount == n;
    }
};