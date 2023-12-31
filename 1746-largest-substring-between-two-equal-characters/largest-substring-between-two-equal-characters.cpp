class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ml=-1;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    ml=max(ml,j-i-1);
                }
            }
        }
        return ml;
    }
};