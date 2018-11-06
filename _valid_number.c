bool isNumber(char* s) {
    // Parse white spaces
    while(isspace(*s)) s++;
    
    // Parse '-' or '+' signs
    if(*s == '-' || *s == '+')
        s++;
    
    // Check for invalid starting 'e'
    if(*s == 'e')
        return false;

    bool dot = false;
    bool exp = false;
    bool num = false;
    bool enm = false;

    // Parse number
    while(*s) {
        switch(*s) {
            // Parse digits
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                num = true;
                if(exp)
                    enm = true;
                break;
            // Parse decimal point
            case '.':
                if(dot || exp)
                    return false;
                dot = true;
                break;
            // Parse exponent
            case 'e':
                if(exp || !num)
                    return false;
                exp = true;
                if(*(s+1) == '+' || *(s+1) == '-')
                    s++;
                break;
            // Parse other cases
            default:
                // Parse end whitespaces
                while(isspace(*s)) s++;
                // If not end of string, return false
                if(*s) return false;
                // If end of string, return true
                if(exp)
                    return enm && num;
                else
                    return num;
        }

        s++;
    }
    
    if(exp)
        return enm && num;
    else
        return num;
}
