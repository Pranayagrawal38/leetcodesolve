class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mp;
        long long sum = 0, gridSum = 0;
        for (int i = 1; i <= n * n; i++) {
            sum += i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                mp[grid[i][j]]++;
            }
        }

        int a = 0;
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2) {
                a = i;
                break; 
            }
        }

        int b = sum - (gridSum - a);

        return {a, b};
    }
};