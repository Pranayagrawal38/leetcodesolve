class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int x=n/2;
        int countleft=0;
        int countright=0;

        for (int i=0;i<x;i++)
        {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            countleft ++;
        }
          for (int i=x;i<n;i++)
        {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            countright ++;
        }
        return (countleft==countright);
    }
};