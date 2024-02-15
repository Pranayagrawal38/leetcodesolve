class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> t(n);
        t[0]=nums[0];
        for(int i=1;i<n;i++)
            t[i]=t[i-1]+nums[i];
        for(int i=n-1;i>=0;i--)
        {
            if(t[i]-nums[i]>nums[i])
                return t[i];
        }
        return -1;
    }
};