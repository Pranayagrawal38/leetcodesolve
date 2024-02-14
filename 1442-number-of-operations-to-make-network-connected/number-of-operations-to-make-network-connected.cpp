class Disjoint {
public:
    vector<int> parent, size;
    Disjoint(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findupar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findupar(parent[node]);
    }
    void unionbysize(int x, int y) {
        int parx = findupar(x);
        int pary = findupar(y);
        if (parx == pary)
            return;
        if (size[parx] < size[pary]) {
            parent[parx] = pary;
            size[pary] += size[parx];
        } else {
            parent[pary] = parx;
            size[parx] += size[pary];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       Disjoint ds(n);
       int extra = 0;
       for (auto it : connections) {
           int x = it[0];
           int y = it[1];
           if (ds.findupar(x) == ds.findupar(y))
               extra++;
           else {
               ds.unionbysize(x, y);
           }
       } 
       int c = 0;
       for (int i = 0; i < n; i++) {
           if (ds.parent[i] == i)
               c++;
       }
       int ans = c - 1;
       if (extra >= c - 1)
           return ans;
       return -1;
    }
};
