// https://leetcode.com/problems/implement-trie-prefix-tree/description/


typedef struct {
    struct Trie* sub[26];
    bool end;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    return calloc(1, sizeof(Trie));
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    while(*word) {
        if(obj -> sub[*word - 'a'] == NULL) {
            obj -> sub[*word - 'a'] = calloc(1, sizeof(Trie));
        }

        obj = obj -> sub[*word - 'a']; word++;
    }
    obj -> end = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    while(*word) {
        if(obj -> sub[*word - 'a'] == NULL)
            return false;
        obj = obj -> sub[*word - 'a'];
        word++;
    }

    return obj -> end;

}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    while(*prefix) {
        if(obj -> sub[*prefix - 'a'] == NULL)
            return false;
        obj = obj -> sub[*prefix - 'a'];
        prefix++;
    }
    
    return true;
}

void trieFree(Trie* obj) {
    for(int index = 0; index < 26; index++)
        if(obj -> sub[index] != NULL)
            trieFree(obj -> sub[index]);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */
