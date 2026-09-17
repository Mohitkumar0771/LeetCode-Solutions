class Solution {
    public List<List<String>> printTree(TreeNode root) {
        int height = getHeight(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;

        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<String> row = new ArrayList<>(Collections.nCopies(n, ""));
            res.add(row);
        }

        fillMatrix(root, res, 0, (n - 1) / 2, height);
        return res;
    }

    private int getHeight(TreeNode node) {
        if (node == null) return -1;
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    private void fillMatrix(TreeNode node, List<List<String>> res, int r, int c, int height) {
        if (node == null) return;

        res.get(r).set(c, Integer.toString(node.val));

        int offset = 1 << (height - r - 1);
        if (node.left != null) {
            fillMatrix(node.left, res, r + 1, c - offset, height);
        }
        if (node.right != null) {
            fillMatrix(node.right, res, r + 1, c + offset, height);
        }
    }
}