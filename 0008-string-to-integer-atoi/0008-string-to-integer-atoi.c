int myAtoi(char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

   
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

   
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }

   
    while (str[i] >= '0' && str[i] <= '9') {
        int digit = str[i] - '0';
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)){
            return (sign == 1)? INT_MAX : INT_MIN;
        }
        result = (result * 10) + digit;
        i++;
    }

    return sign * result;
}