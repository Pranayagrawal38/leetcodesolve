class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowOnes(n, 0), colOnes(m, 0), rowZeros(n, 0), colZeros(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowOnes[i] += grid[i][j];
                colOnes[j] += grid[i][j];
                rowZeros[i] += (grid[i][j] == 0);
                colZeros[j] += (grid[i][j] == 0);
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] = (rowOnes[i] + colOnes[j]) - (rowZeros[i] + colZeros[j]);
            }
        }

        return diff;
    }
};