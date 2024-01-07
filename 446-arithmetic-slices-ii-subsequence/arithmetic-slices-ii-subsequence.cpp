class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
    vector<unordered_map<long, long>> dp(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long delta = (long long)nums[i] - (long long)nums[j];
            if (delta < INT_MIN || delta > INT_MAX) continue;
            auto it = dp[j].find(delta);
            long long cnt = it != dp[j].end() ? it->second : 0;
            dp[i][delta] += cnt + 1;
            ans += cnt;
        }
    }
    return (int)ans;

    }
};