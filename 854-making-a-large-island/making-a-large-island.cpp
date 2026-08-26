class Solution {
private:
    int n;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int r, int c, int island_id, vector<vector<int>>& grid) {
        grid[r][c] = island_id;
        int area = 1;

        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                area += dfs(nr, nc, island_id, grid);
            }
        }
        return area;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> island_area;
        int island_id = 2;
        int max_size = 0;

        // Step 1: Label each island and store its area
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j, island_id, grid);
                    island_area[island_id] = area;
                    max_size = max(max_size, area);
                    island_id++;
                }
            }
        }

        // If the grid is already all 1s (or max island equals n*n)
        if (max_size == n * n) return max_size;

        // Step 2: Check each 0 to see max potential island size
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbor_islands;
                    for (auto& dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            neighbor_islands.insert(grid[ni][nj]);
                        }
                    }

                    int current_size = 1;
                    for (int id : neighbor_islands) {
                        current_size += island_area[id];
                    }
                    max_size = max(max_size, current_size);
                }
            }
        }

        return max_size;
    }
};