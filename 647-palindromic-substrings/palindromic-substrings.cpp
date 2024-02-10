class Solution {
public:
bool check(string s,int start,int end){
    while(start<end){
        if(s[start++]!=s[end--])
        return false;
    }
    return true;
}
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s,i,j))
                ans++;
            }
        }
        return ans;
    }
};