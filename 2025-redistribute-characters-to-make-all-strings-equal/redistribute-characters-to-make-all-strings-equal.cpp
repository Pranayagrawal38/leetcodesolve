class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(auto it:words){
            for(int i=0;i<it.size();i++){
                mp[it[i]]++;
            }
        }
        for(auto it:mp){
            if(it.second%words.size()!=0)
            return false;
        }
        return true;

    }
};