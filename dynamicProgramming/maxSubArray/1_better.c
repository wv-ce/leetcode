int maxSubArray(int *nums, int numsSize)
{
    int pre = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        pre = fmax(nums[i], pre + nums[i]);
        max = fmax(max, pre);
    }
    return max;
}