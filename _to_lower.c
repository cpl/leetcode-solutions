char* toLowerCase(char* s) {
    char* start = s;
    while(*s) {
        if(*s >= 'A' && *s <= 'Z')
            *s = 'a' + (*s%'A');
        s++;
    }

    return start;
}
