#include <iostream>
#include <vector>

bool canPartition(std::vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    // If the sum is odd, it cannot be divided into two equal subsets
    if (sum % 2 != 0) {
        return false;
    }

    int target = sum / 2;
    int n = nums.size();

    // Create a 2D DP array dp[i][j], where dp[i][j] is true if there is a subset
    // of nums[0..i-1] with a sum of j.
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // Base case: an empty subset can always have a sum of 0.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            // If the current number is greater than the target sum, we cannot include it.
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Consider two cases: include the current number or exclude it.
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    std::vector<int> nums = {3, 1, 1, 2, 2, 1};
    if (canPartition(nums)) {
        std::cout << "The set can be divided into two equal-sum subsets." << std::endl;
    } else {
        std::cout << "The set cannot be divided into two equal-sum subsets." << std::endl;
    }

    return 0;
}
