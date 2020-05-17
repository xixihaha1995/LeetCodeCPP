#include "headers.h"

class Solution
{
public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
          
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i][m + 1] = INT_MAX;
      for (int j = 1; j <= m; ++j)
        dp[i][j] = *min_element(dp[i - 1].begin() + j - 1, 
                                dp[i - 1].begin() + j + 2) + A[i - 1][j - 1];      
    }
    return *min_element(dp[n].begin() + 1, dp[n].end() - 1);
  }
};

TEST(minFallingPathSum, minimumTotal_test)
{
    Solution s;
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int ans = 12;
    EXPECT_EQ(s.minFallingPathSum(A), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}