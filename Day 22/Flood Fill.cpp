class Solution
{
public:
    void solve(vector<vector<int>> &image, int r, int c, int color, int pcol)
    {
        int n = image.size();
        int m = image[0].size();
        int i = r, j = c;
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        if (image[r][c] != pcol || image[r][c] == color)
            return;

        image[r][c] = color;

        solve(image, i - 1, j, color, pcol);
        solve(image, i, j - 1, color, pcol);
        solve(image, i + 1, j, color, pcol);
        solve(image, i, j + 1, color, pcol);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        // vector<vector<int>> res;

        int pcol = image[sr][sc];
        solve(image, sr, sc, color, pcol);
        return image;
    }
};