int trap(int *height, int heightSize)
{
    if (heightSize == 0)
    {
        return 0;
    }
    int ans = 0;
    int n = heightSize;
    int leftMax[n], rightMax[n];
    memset(leftMax, 0, sizeof(leftMax));
    memset(rightMax, 0, sizeof(rightMax));
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = fmax(leftMax[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = fmax(rightMax[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans += fmin(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}