class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];

        // Directions: Right, Down, Left, Up
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};

        int r = 0, c = 0, d = 0;

        for (int val = 1; val <= n * n; val++) {
            res[r][c] = val;

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || res[nr][nc] != 0) {
                d = (d + 1) % 4;
            }

            r += dr[d];
            c += dc[d];
        }

        return res;
    }
}