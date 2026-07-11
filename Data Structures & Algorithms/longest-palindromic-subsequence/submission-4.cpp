class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string reversedS = s;
        reverse(reversedS.begin(),reversedS.end());
        return longestCommonSubsequence(s, reversedS);
    }
    int longestCommonSubsequence(string text1, string text2) {
        // Initializing with 0 ensures base cases are pre-filled
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        // Moving backward from the end of the strings
        for (int i = text1.size() - 1; i >= 0; i--) {      // Fixed: i-- this is the most imp thing to remember that we have to move backwards in the bottom up DP approach . 
            for (int j = text2.size() - 1; j >= 0; j--) {  // Fixed: j--
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};