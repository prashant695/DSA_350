// https://leetcode.com/problems/flood-fill/

// Time Complexity: O(N), where NN is the number of pixels in the image.
// Space Complexity: O(N), N the size of the implicit call stack when calling dfs.

class Solution
{
public:
    vector<vector<int>> f(vector<vector<int>> &image, int sr, int sc, int newColor, int pre)
    {
        if (sr >= image.size() || sr < 0)
            return image;
        if (sc >= image[0].size() || sc < 0)
            return image;
        if (image[sr][sc] != pre)
            return image;
        image[sr][sc] = newColor;

        f(image, sr + 1, sc, newColor, pre);
        f(image, sr - 1, sc, newColor, pre);
        f(image, sr, sc + 1, newColor, pre);
        f(image, sr, sc - 1, newColor, pre);

        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int pre = image[sr][sc];
        if (pre != newColor)
            f(image, sr, sc, newColor, pre);
        return image;
    }
};
