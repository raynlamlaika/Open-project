#include <stdbool.h>

bool isPalindrome(int x) {
    unsigned int i =x ;
    int k =0;
    while (i)
    {    
        if (k > (2147483647 / 10) || (k == (2147483647 / 10) && (x % 10) > 7))
            return 0;
        k = k*10 + i % 10;
        i /= 10;
    }

    if (k == x && k >= 0)
        return (k == x);
    return (0);
}