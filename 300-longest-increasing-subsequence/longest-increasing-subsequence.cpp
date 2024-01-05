class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) 
                v[i]=max(v[i],v[j]+1);
            }
        }
        sort(v.begin(),v.end());
        return v[v.size()-1];
    }
};