// count of pallindromic substrings leetcode iterative code

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> isPallindrome = vector<vector<int>>(n, vector<int>(n));
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n));

        for (int k = 0; k < n; k++) {
            int i = k, j = k;
            while (i >= 0 && j < n) {
                if (s[i] != s[j]) break;
                isPallindrome[i][j] = true;
                i--; j++;
            }

            i = k, j = k+1;
            while (i >= 0 && j < n) {
                if (s[i] != s[j]) break;
                isPallindrome[i][j] = true;
                i--; j++;
            }
        }

        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (i == j) {
                    dp[i][j] = 1; 
                    continue;
                }
                if (i > j) { // this condition will never be 
                            // called based upon how we're running our loop
                    dp[i][j] = 0; 
                    continue;
                }
                int x = dp[i+1][j];
                int y = dp[i][j-1];
                int repetition = dp[i+1][j-1];
                dp[i][j] = isPallindrome[i][j] + x + y - repetition;
            }
        }

        return dp[0][n-1];
    }
};
