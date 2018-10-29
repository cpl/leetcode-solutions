// https://leetcode.com/problems/valid-parentheses/description/


#include <stdlib.h>


typedef struct stack {
    size_t SP;
    char*  data;
    size_t cap;
} stack;



// NEW(stack*, size_t), allocate a stack of given size.
#define NEW(s, n) ((s = (stack*)malloc(sizeof(stack))),\
                   (s -> cap = n),                     \
                   (s -> SP = 0),                      \
                   (s -> data = (char*)calloc(n, sizeof(char))))

// CLEAR(stack*), reset the stack pointer.
#define CLEAR(s)   (s -> SP = 0)

// ISEMPTY(stack*), check if the stack pointer is 0.
#define ISEMPTY(s) (((s -> SP) == 0))

// PUSH(stack*, size_t), put a given value on the top of the stack
#define PUSH(s, v) (s -> data[(s -> SP)++] = (char)v)

// POP(s), return the value on top of the stack, or 0 if the stack is empty.
#define POP(s) (ISEMPTY(s) ? 0 : s -> data[--(s -> SP)])

// ISFULL(s), check if the stack is full
#define ISFULL(s) (((s -> SP) == (s -> cap)))


char par_map[] = {
    ['('] = ')',
    ['['] = ']',
    ['{'] = '}',
};


bool isValid(char* s) {
    stack* STACK;
    NEW(STACK, strlen(s));

    while(*s) {
        switch(*s) {
        case '(':
        case '[':
        case '{':
            PUSH(STACK, *s); break;
        default:
            if(par_map[POP(STACK)] != *s)
                return false;
        }
        
        s++;
    }
    
    return ISEMPTY(STACK);
}
