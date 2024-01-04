class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int c=0;
        for(auto it:mp){
            if(it.second==1)
            return -1;
            c+=ceil((double)(it.second)/3);
        }
        return c;

    }
};