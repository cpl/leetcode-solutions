
typedef struct stack {
    size_t SP;
    size_t cap;
    int* data;
} stack;



// NEW(stack*, size_t), allocate a stack of given size.
#define NEW(s, n) ((s = (stack*)malloc(sizeof(stack))),\
                   (s -> cap = n),                     \
                   (s -> SP = 0),                      \
                   (s -> data = (int*)calloc(n, sizeof(int))))

// PUSH(stack*, size_t), put a given value on the top of the stack
#define PUSH(s, v) (s -> data[(s -> SP)++] = (int)v)

// POP(s), return the value on top of the stack, or 0 if the stack is empty.
#define POP(s) (s -> data[--(s -> SP)])

int evalRPN(char** tokens, int tokensSize) {

    stack* STACK; NEW(STACK, tokensSize);
    
    int val, x, y;

    for(int index = 0; index < tokensSize; index++) {

        // Numbers starting with sign or multi-digit
        if(strlen(tokens[index]) != 1) {
            PUSH(STACK, atoi(tokens[index]));
            continue;
        }

        switch(*tokens[index]) {
            // Operations
            case '+':
                x = POP(STACK);
                y = POP(STACK);
                val = x + y;
                PUSH(STACK, val); break;
            case '-':
                x = POP(STACK);
                y = POP(STACK);
                val = y - x;
                PUSH(STACK, val); break;
            case '*':
                x = POP(STACK);
                y = POP(STACK);
                val = x * y;
                PUSH(STACK, val); break;
            case '/':
                x = POP(STACK);
                y = POP(STACK);
                val = y / x;
                PUSH(STACK, val); break;
            // New single digit value
            default:
                PUSH(STACK, *tokens[index]%'0');
        } // switch
    } // for

    return POP(STACK);
}
