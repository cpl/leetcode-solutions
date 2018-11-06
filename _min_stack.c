typedef struct {
    int  cap;
    int  len;
    int  min;
    int* elements;
} MinStack;


/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));

    stack -> elements = (int*)malloc(sizeof(int)*maxSize);
    stack -> cap = maxSize;
    stack -> len = 0;
    stack -> min = INT_MAX;
    
    return stack;
}


void minStackPush(MinStack* stack, int x) {
    if(stack -> len >= stack -> cap)
        return;
    
    if(x < stack -> min)
        stack -> min = x;

    stack -> elements[stack -> len] = x; stack -> len++;
}


void minStackPop(MinStack* stack) {
    if(stack -> len == 0)
        return;

    stack -> len--;


    if(stack -> min == stack -> elements[stack -> len]) {
        stack -> min = INT_MAX;
        for(int index = 0; index < stack -> len; index++)
            if(stack -> elements[index] < stack -> min)
                stack -> min = stack -> elements[index];
    }
}


int minStackTop(MinStack* stack) {
    return stack -> elements[stack -> len - 1];    
}


int minStackGetMin(MinStack* stack) {
    return stack -> min;
}


void minStackFree(MinStack* stack) {
    for(int index = 0; index < stack -> len; index++)
        printf("[%d] -> ", stack -> elements[index]);
    printf("\n");

    free(stack);
}


/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
