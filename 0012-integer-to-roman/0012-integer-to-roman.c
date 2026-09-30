char* intToRoman(int num) {
    char* stack = (char*)malloc(15 * sizeof(char));
    int top = 0;
#define push(el)                                                          \
    {                                                                          \
        stack[top++] = el;                                                     \
    }
    while (num > 0) {
        if (num >= 1000) {
            push('M');
            num -= 1000;
        } else if (num >= 900) {
            push('C');
            push('M');
            num -= 900;
        } else if (num >= 500) {
            push('D');
            num -= 500;
        } else if (num >= 400) {
            push('C');
            push('D');
            num -= 400;
        } else if (num >= 100) {
            push('C');
            num -= 100;
        } else if (num >= 90) {
            push('X');
            push('C');
            num -= 90;
        } else if (num >= 50) {
            push('L');
            num -= 50;
        } else if (num >= 40) {
            push('X');
            push('L');
            num -= 40;
        } else if (num >= 10) {
            push('X');
            num -= 10;
        } else if (num >= 9) {
            push('I');
            push('X');
            num -= 9;
        } else if (num >= 5) {
            push('V');
            num -= 5;
        } else if (num >= 4) {
            push('I');
            push('V');
            num -= 4;
        } else if (num >= 1) {
            push('I');
            num -= 1;
        }
    }
    char* result = (char*)malloc((top+1) * sizeof(char));
    result[top] = '\0';
    for (int i = 0; i < top; i++) {
        result[i] = stack[i];
    }
    free(stack);
    return result;
}