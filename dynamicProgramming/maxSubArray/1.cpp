#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0;
        int ans = nums[0];
        for (const auto &x : nums)
        {
            pre = max(pre + x, x);
            ans = max(ans, pre);
        }
        return ans;
    }
};