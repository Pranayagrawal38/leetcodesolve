
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime){
        int t=0;
        int i=0,j=0;
        while (i<neededTime.size()&&j<neededTime.size()){
            int c=0,cm=0;
            while (j<neededTime.size()&&colors[i]==colors[j]){
                c+=neededTime[j]; 
                cm=max(cm,neededTime[j]);
                j++;
            }
            t+=c-cm;
            i=j; 
        }
        return t;
    }
};

