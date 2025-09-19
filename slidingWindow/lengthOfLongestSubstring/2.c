int lengthOfLongestSubstring(char * s){
    int hash[128] = {0};
    int left = 0, right = 0;
    int maxLen = 0;
    while (s[right] != '\0') {
        if(hash[s[right]] && left < hash[s[right]]){
            left = hash[s[right]];
        }
        hash[s[right]] = right + 1;
        maxLen = (right - left + 1) > maxLen ? (right - left + 1) : maxLen;
        right++;
    }
    return maxLen;
}

// hash数组存储字符上次出现的位置+1
// 遇到重复字符时，left指针直接跳到上次出现位置的下一个位置
// 时间复杂度O(n)，空间复杂度O(1)