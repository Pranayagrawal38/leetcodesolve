class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
         vector<int> nof(nums.size() + 1);
        
        vector<vector<int>> ans;
        for (int c : nums) {
            if (nof[c] >= ans.size()) {
                ans.push_back({});
            }
             ans[nof[c]].push_back(c);
            nof[c]++;
        }
        
        return ans;
    }
};