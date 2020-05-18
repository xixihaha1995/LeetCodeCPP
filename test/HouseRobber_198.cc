#include "headers.h"

class Solution
{
public:
  int rob(<vector<int>& nums) {
    if nums is empty{
      return 0;
    }
    int len = nums.size();
    vector<int> dp = 
    for(int i = 0; i < len; ++i){
      dp[i] = max((i>0) ? dp[i-1] : nums[i], (i>1) ? dp[i-2] : nums[i]);
    }
    return dp.back();
  }
};

TEST(rob, rob_test)
{
    Solution s;
    vector<int> A = { 1，2};
    int ans = 2;
    EXPECT_EQ(s.minFallingPathSum(A), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}