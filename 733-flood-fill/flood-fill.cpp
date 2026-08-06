class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int origColor, int newColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) return;
        if (image[r][c] != origColor) return;

        image[r][c] = newColor;

        dfs(image, r + 1, c, origColor, newColor);
        dfs(image, r - 1, c, origColor, newColor);
        dfs(image, r, c + 1, origColor, newColor);
        dfs(image, r, c - 1, origColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];
        if (origColor != color) {
            dfs(image, sr, sc, origColor, color);
        }
        return image;
    }
};