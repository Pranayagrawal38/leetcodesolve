class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int m = k;

        int dp[110][110] = {};
        for (int i=1; i <= n; ++i) {
            for (int j=0; j<=i&& j <= m; ++j) {
                int r=0;
                int c=0;
                dp[i][j]=INT_MAX;
                if (j) {
                    dp[i][j]=dp[i-1][j-1];
                }
                for (int k=i; k>=1;k--) {
                    if (s[k-1] != s[i-1]) {
                        r++;
                    } else {
                        c++;
                    }

                    if (r>j) {
                        break;
                    }

                    if (c ==1) {
                        dp[i][j] = min(dp[i][j], dp[k-1][j - r]+1);
                    } else if (c < 10) {
                        dp[i][j] = min(dp[i][j], dp[k-1][j - r] + 2);
                    } else if (c < 100) {
                        dp[i][j] = min(dp[i][j], dp[k-1][j - r] + 3);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[k-1][j - r] + 4);
                    }
                }
            }
        }

        return dp[n][m];
    }
};