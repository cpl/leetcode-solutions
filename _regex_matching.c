// https://leetcode.com/problems/regular-expression-matching/description/
// Passes only 90% of tests for now
// fails:
// s:  aaa
// r:  ab*a*c*a
// because final `a` is not matched properly because `a` consumes `a`, `a*` consumes `aa`


static char* str;
static char* reg;

bool parse_star();
bool parse_dott();
bool parse_char();
bool parse_token();
bool parse_all();

static dotcount = 0;



bool isMatch(char* s, char* r) {
    str = s;
    reg = r;
    dotcount = 0;

    return parse_all();
}


bool parse_all() {
    while(*reg)
        if(!parse_token())
            return false;
    
    if(*str != 0 || *reg != 0)
        return false;

    return true;
}


bool parse_token() {
    switch(*reg) {
        case 0  : return false;
        case '.': return parse_dott();
        case '*': return parse_star();
        default :
            return parse_char();
    }
}


bool parse_star() {
    printf("ERR\n");
    return false;
}

bool parse_dott() {
    if(*(reg+1) == '*') {
        printf("PARSE . *; ");
        while(*(reg+2+dotcount) == '.')
            dotcount++;

        while(*(str+dotcount) && *str != *(reg+2+dotcount)) {
            printf("%c", *str);
            str++;
        }
        printf("\n");

        dotcount = 0;
        reg+=2;

        if(*str == 0 && *reg != 0) {
            printf("PARSE .* 0;\n");
            return false;
        }

        return true;
    } else {
        if(*str == 0) {
            printf("PARSE . 0;\n");
            return false;
        }
        printf("PARSE . %c;\n", *str);
        str++; reg++;
        return true;
    }

    return false;
}




bool parse_char() {
    if(*(reg+1) == '*') {
        printf("PARSE * %c; ", *reg);

        while(*reg == *(reg+2+dotcount))
            dotcount++;

        while(*str && *str == *reg) {
            printf("%c", *str);
            str++;
        }
        str -= dotcount;
        dotcount = 0;
        printf("\n");
        reg+=2;
        return true;
    } else {
        printf("PARSE %c %c;\n", *reg, *str);
        return (*str++ == *reg++);
    }
    return false;
}



