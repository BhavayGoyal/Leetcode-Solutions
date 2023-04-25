// longest common sub-sequence leetcode recursive code

class Solution {
public:
    string a, b;
    vector<vector<int>> dp;

    int lcs(int i, int j) {
        if (i == a.size() || j == b.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = max(lcs(i+1, j), lcs(i, j+1));
        if (a[i] == b[j]) ans = max(ans, 1+lcs(i+1, j+1));
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string &x, string &y) {
        a = x, b = y;
        dp = vector<vector<int>>(a.size()+1, vector<int>(b.size()+1, -1));
        return lcs(0, 0);
    }
};