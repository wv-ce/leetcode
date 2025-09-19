char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 2) return s;
    int max = 1;
    int start = 0;
    int dp[len][len];
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    for (int L = 2; L <= len; L++) {
        for (int i = 0; i < len - L + 1; i++) {
            int j = i + L - 1;
            if (s[i] != s[j]) {
                dp[i][j] = 0;
            } else {
                if (L < 4) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            if (dp[i][j] && L > max) {
                max = L;
                start = i;
            }
        }
    }
    char* res = (char*)malloc(sizeof(char) * (max + 1));
    strncpy(res, s + start, max);
    res[max] = '\0';
    return res;
}

/* 最后取出子串的另一种写法：
 * s[start+max]='\0';
 * return s+start;
 */
