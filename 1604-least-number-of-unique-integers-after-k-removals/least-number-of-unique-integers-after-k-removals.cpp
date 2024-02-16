class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr)
         mp[it]++;
        vector<int>freq;
        for(auto it:mp){
            freq.push_back(it.second);
        }
        int ans=0;
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            if(freq[i]<k){
                k-=freq[i];
                freq[i]=0;
            }
            else if(k<=freq[i]){
                freq[i]-=k;
                k=0;
            }
            if(freq[i]!=0)
            ans++;
        }
        return ans;
    }
};