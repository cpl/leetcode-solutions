// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <ctype.h>
#include <limits.h>


int myAtoi(register char* str) {
    // Skip whitespaces
    while(isspace(*str)) str++;

    // Decide sign
    int pos = 1;
    switch(*str) {
        case '-': pos = 0; ++str; break;
        case '+':           ++str; break;
    }

    // Accumulator
    register int acc = 0;
    
    // Char to digit
    register int chr;

    // Parse digits
    while(isdigit(*str)) {
        chr = (int)(*str % '0');

        // Check for overflow
        if(acc > (INT_MAX/10) || (acc == (INT_MAX/10) && chr > INT_MAX%10))
            return pos ? INT_MAX : INT_MIN;

        // Increment accumulator
        acc = acc*10 + chr; str++;
    }

    return pos ? acc : -acc;
}
