// Time Complexity: O(N)
// Space Complexity: O(N)

void dfs(vector<vector<int>> &image, int i, int j, int val, int newColor)
{
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
        image[i][j] == newColor || image[i][j] != val)
        return;
    image[i][j] = newColor;
    dfs(image, i - 1, j, val, newColor);
    dfs(image, i + 1, j, val, newColor);
    dfs(image, i, j - 1, val, newColor);
    dfs(image, i, j + 1, val, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y,
                              int newColor)
{
    // Write your code here.
    int val = image[x][y];
    dfs(image, x, y, val, newColor);
    return image;
}