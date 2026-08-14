class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    count++;
                    dfs(grid, visited, i, j, m, n, count);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c, int m, int n, int islandNum) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }
        if (grid[r][c] == '0' || visited[r][c] != 0) {
            return;
        }

        visited[r][c] = islandNum;

        dfs(grid, visited, r + 1, c, m, n, islandNum);
        dfs(grid, visited, r - 1, c, m, n, islandNum);
        dfs(grid, visited, r, c + 1, m, n, islandNum);
        dfs(grid, visited, r, c - 1, m, n, islandNum);
    }
};
