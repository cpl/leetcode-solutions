#define LC_C 'z'-'a'+1

bool canConstruct(char* ransomNote, char* magazine) {
    int arr[LC_C] = {0,};

    while(*magazine) {
        arr[*magazine%'a']++; magazine++;
    }
    
    for(int index = 0; index < LC_C; index++) {
        printf("%c: %d\n", index+'a', arr[index]);
    }

    while(*ransomNote) {
        if(arr[*ransomNote%'a']-- == 0)
            return false;
        ransomNote++;
    }

    return true;
}
