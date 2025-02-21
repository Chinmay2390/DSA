// flood_fill.cpp - DFS-based flood fill on image grid
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor)
        return;

    image[i][j] = newColor;

    dfs(image, i + 1, j, newColor, oldColor);
    dfs(image, i - 1, j, newColor, oldColor);
    dfs(image, i, j + 1, newColor, oldColor);
    dfs(image, i, j - 1, newColor, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor != newColor)
        dfs(image, sr, sc, newColor, oldColor);
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    for (auto& row : result) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}

