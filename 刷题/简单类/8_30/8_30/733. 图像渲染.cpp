class Solution {
public:
	void UpColor(vector<vector<int>>& image, int sr, int sc, const int& newColor, const int oldColor)
	{
		if (sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size() || \
			image[sr][sc] != oldColor || image[sr][sc] == newColor)
			return;
		image[sr][sc] = newColor;
		UpColor(image, sr + 1, sc, newColor, oldColor);
		UpColor(image, sr, sc + 1, newColor, oldColor);
		UpColor(image, sr - 1, sc, newColor, oldColor);
		UpColor(image, sr, sc - 1, newColor, oldColor);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		UpColor(image, sr, sc, newColor, image[sr][sc]);
		return image;
	}
};