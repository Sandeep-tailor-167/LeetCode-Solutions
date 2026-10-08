bool isMatch(char* s, char* p) {
    int sLen = 0;
    while (s[sLen] != '\0') sLen++;

    int pLen = 0;
    while (p[pLen] != '\0') pLen++;

    // Allocate DP table: dp[i][j] represents if s[0..i-1] matches p[0..j-1]
    bool** dp = (bool**)malloc((sLen + 1) * sizeof(bool*));
    for (int i = 0; i <= sLen; i++) {
        dp[i] = (bool*)malloc((pLen + 1) * sizeof(bool));
        for (int j = 0; j <= pLen; j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    // Handle patterns with '*' matching an empty string
    for (int j = 2; j <= pLen; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]; // Zero occurrences
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j]; // One or more occurrences
                }
            }
        }
    }

    bool result = dp[sLen][pLen];

    for (int i = 0; i <= sLen; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}