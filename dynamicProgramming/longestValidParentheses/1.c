int longestValidParentheses(char* s) {
    int max = 0;
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }// 如果字符串为空，直接返回0，否则下面的 dp[n]就会出错
    int dp[n];
    memset(dp, 0, sizeof(dp));// memset用来将dp数组初始化为0
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            max = fmax(max, dp[i]);// fmax 是 math.h 中的函数，用来求两个数的最大值
        }
    }
    return max;
}