class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int i=0,j=0;
        bool p=false;
        map<char,int>mp;
        for(int i=0;i<k;i++)
        mp[s1[i]]++;
        int c=mp.size();
        while(j<s2.size()){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]]==0)
                c--;
            }
            if(j-i+1<k)
            j++;
            else if(j-i+1==k){
                if(c==0)
                p=true;
            
            if(mp.find(s2[i])!=mp.end()){
                mp[s2[i]]++;
                if(mp[s2[i]]==1)
                c++;
            }
            i++;
            j++;
            }

        
            

        }
        return p;
    }
};