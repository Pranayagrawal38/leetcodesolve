class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string s1=q.front().first;
            int c=q.front().second;
            q.pop();
            if(s1==endWord)
            return c;
            for(int i=0;i<s1.size();i++){
                char ch=s1[i];
                for(char chi='a';chi<='z';chi++){
                    s1[i]=chi;
                    if(s.find(s1)!=s.end()){
                        q.push({s1,c+1});
                        s.erase(s1);
                    }
                }
                s1[i]=ch;
            }
        }
        return 0;
    }
};