class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        long long n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int c=1,ans=1,prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev+1)
            c++;
            else if(nums[i]!=prev)
                c=1;
               // c=0;
            prev=nums[i];
            ans=max(c,ans);

        }
        //int d=max+1;
        return ans;
    }
};