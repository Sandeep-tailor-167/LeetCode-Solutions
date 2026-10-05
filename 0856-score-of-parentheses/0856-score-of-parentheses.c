int score(const char *s, int l, int r);
int scoreOfParentheses(char* s) {
    return score(s,0,strlen(s)-1);
}
int score(const char *s, int l, int r) {
    if (l >= r) return 0;
    if (l + 1 == r) return 1; 

    int total = 0, balance = 0;

    for (int i = l; i <= r; i++) {
        balance += (s[i] == '(') ? 1 : -1;

       
        if (balance == 0) {
            if (i - l == 1)
                total += 1;             
            else
                total += 2 * score(s, l + 1, i - 1); 

            l = i + 1;
        }
    }
    return total;
}