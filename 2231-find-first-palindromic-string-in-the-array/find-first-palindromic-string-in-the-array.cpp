class Solution {
public:
string ans;
bool check(string &s){
    int n=s.size();
    string temp=s;
    string p="";
    for(int i=n-1;i>=0;i--){
        p+=s[i];
    }
    if(p==temp)
    return true;
    return false;

}
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(check(words[i])){
                ans=words[i];
                break;
            }
            
        }
        return ans;
    }
};