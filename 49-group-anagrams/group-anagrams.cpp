class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(int i=0;i<nums.size();i++){
            string t=nums[i];
            sort(t.begin(),t.end());
            mp[t].push_back(nums[i]);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};