// longest common sub-sequence leetcode iterative code

class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        vector<vector<int>> dp(a.size()+1, vector<int> (b.size()+1));
        for (int i = a.size(); i >= 0; i--) {
            for (int j = b.size(); j >= 0; j--) {
                if (i == a.size() || j == b.size()) { dp[i][j] = 0; continue; }
                int ans = max(dp[i+1][j], dp[i][j+1]);
                if (a[i] == b[j]) ans = max(ans, 1+dp[i+1][j+1]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};
