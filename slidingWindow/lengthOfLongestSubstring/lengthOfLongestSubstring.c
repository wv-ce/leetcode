int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    int left = 0, right = 0;
    int max_len = 1;
    for(; right < len; right++) {
        int i;
        for(i = left; i < right; i++) {
            if (s[i] == s[right]) {
                left = i + 1;
                break;
            }
        }
        if (i == right) {
            max_len = max_len > (right - left + 1) ? max_len : (right - left + 1);
        }
    }
    return max_len;
}