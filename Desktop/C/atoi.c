int myAtoi(char* s) {
    int i = 0;
    int sing = 1;
    long rs = 0;
    while (s[i] && s[i] == 32)
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sing = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        rs = (rs * 10 ) + (s[i] - '0');
        if (rs > 2147483647) {
            return (sing == 1) ? 2147483647 : -2147483648;
        }
        i++;
    }
    return (int)(rs*sing);
}
