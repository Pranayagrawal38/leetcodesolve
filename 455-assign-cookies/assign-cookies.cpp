class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort the greed factors in ascending order
        sort(s.begin(), s.end()); // Sort the cookie sizes in ascending order
        
        int childIndex = 0; // Pointer for iterating over greed factors
        int cookieIndex = 0; // Pointer for iterating over cookie sizes
        int contentChildren = 0; // Count of content children
        
        while (childIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[childIndex]) {
                contentChildren++;
                childIndex++;
                cookieIndex++;
            } else {
                cookieIndex++;
            }
        }
        
        return contentChildren;
    }
};
