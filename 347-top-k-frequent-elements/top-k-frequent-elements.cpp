
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>>pq;

        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(i==0){
                cnt++;
            }
            else{
                if(nums[i]==nums[i-1]){
                    cnt++;
                }
                else{
                    pq.push({cnt,nums[i-1]});
                    cnt=1;
                }
            }
        }
        pq.push({cnt,nums[nums.size()-1]});
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};