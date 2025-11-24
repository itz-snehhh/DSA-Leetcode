class Solution {
public:
// Complexity becomes O(n²) time and O(n²) space.”
// Much better than brute-force O(n³).

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1, start = 0;

        // Length 1 substrings
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // Length 2 substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;

                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
