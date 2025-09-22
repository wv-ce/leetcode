int maxSubArray(int *nums, int numsSize)
{
    int n = numsSize;
    int dp[n];
    int max = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = fmax(nums[i], dp[i - 1] + nums[i]);
        max = fmax(max, dp[i]);
    }
    return max;
}