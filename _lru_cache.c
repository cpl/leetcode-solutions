// https://leetcode.com/problems/lru-cache/description/

// Implement a hashmap yourself for O(1) put and get
// or even better, take all this code and implement it in HDL (eg: Verilog)

typedef struct {
    int val;
    int key;

    int next;
    int prev;
} Node;


typedef struct {
    int cap;
    int len;
    int lru;

    Node nodes[];

} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    printf("NEW: %d\n", capacity);

    LRUCache* cache = malloc(sizeof(LRUCache) + sizeof(Node)*capacity);

    cache -> cap = capacity;
    cache -> len = 0;
    cache -> lru = 0;

    cache -> nodes[0].prev = 0;
    cache -> nodes[0].next = 0;

    return cache;
}

int lRUCacheGet(LRUCache* cache, int key) {
    // printf("LRU: %d\n", cache -> lru);
    printf("GET: (%d ", key);
    
    for(int index = 0; index < cache -> len; index++) {
        if(cache -> nodes[index].key == key) {
            Node* node = &(cache -> nodes[index]);
            
            if(index == cache -> lru && cache -> len > 1)
                cache -> lru = node -> next;

            cache -> nodes[node -> prev].next = node -> next;
            cache -> nodes[node -> next].prev = node -> prev;

            node -> next = cache -> lru;
            node -> prev = cache -> nodes[cache -> lru].prev;
            cache -> nodes[cache -> nodes[cache -> lru].prev].next = index;
            cache -> nodes[cache -> lru].prev = index;

            printf("%d) %d\n", node -> val, index);
            // printf("LRU: %d\n", cache -> lru);    
            return node -> val;
        }
    }

    printf("_) _\n");
    return -1;
}

void lRUCachePut(LRUCache* cache, int key, int val) {

    // printf("LRU: %d\n", cache -> lru);    

    for(int index = 0; index < cache -> len; index++) {
        if(cache -> nodes[index].key == key) {
            printf("UPD: (%d %d) %d\n", key, val, index);

            Node* node = &(cache -> nodes[index]);
            node -> val = val;
            
            if(index == cache -> lru && cache -> len > 1)
                cache -> lru = node -> next;
            
            cache -> nodes[node -> prev].next = node -> next;
            cache -> nodes[node -> next].prev = node -> prev;

            node -> next = cache -> lru;
            node -> prev = cache -> nodes[cache -> lru].prev;
            cache -> nodes[cache -> nodes[cache -> lru].prev].next = index;
            cache -> nodes[cache -> lru].prev = index;
            
            // printf("LRU: %d\n", cache -> lru);
            return;
        }
    }
    

    if(cache -> len < cache -> cap) {
        printf("PUT: (%d %d) %d\n", key, val, cache -> len);

        Node* node = &(cache -> nodes[cache -> len++]);
        
        node -> key = key;
        node -> val = val;

        node -> next = (cache -> lru); 
        node -> prev = cache -> nodes[cache -> lru].prev;
        cache -> nodes[cache -> lru].prev = (cache -> len - 1);
        if(cache -> len == 2)
            cache -> nodes[cache -> lru].next = 1;

        // node -> next  = (cache -> len) % (cache -> cap);
        // node -> prev  = (cache -> len == 1) ? (cache -> cap - 1) : (cache -> len - 2);
    } else {
        Node* lru_node = &(cache -> nodes[cache -> lru]);

        lru_node -> key = key;
        lru_node -> val = val;

        printf("RPL: (%d %d) %d\n", key, val, cache -> lru);

        cache -> lru = lru_node -> next;
    }
    
    // printf("LRU: %d\n", cache -> lru);
    return;
}

void lRUCacheFree(LRUCache* cache) {
    free(cache);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
