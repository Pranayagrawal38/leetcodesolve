#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1; // Start or end blocked

        vector<vector<int>> dirs = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark as visited

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int x = cell.first, y = cell.second, dist = grid[x][y];

            if (x == n - 1 && y == n - 1) return dist; // Reached end

            for (auto dir : dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    q.push({newX, newY});
                    grid[newX][newY] = dist + 1; // Mark as visited with distance
                }
            }
        }
        return -1; // Path not found
    }
};
