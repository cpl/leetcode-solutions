typedef struct {
    int* items;

    unsigned int head;
    unsigned int tail;
    unsigned int cap;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    printf("NEW: %d\n", k);

    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue -> items = malloc(sizeof(int)*(k+1));
    queue -> head = 0;
    queue -> tail = 1;
    queue -> cap  = k+1;

    return queue;
}


bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);


/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;

    obj -> items[obj -> tail] = value;
    obj -> tail = (obj -> tail + 1) % (obj -> cap);
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    
    obj -> head = (obj -> head + 1) % (obj -> cap); return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return (myCircularQueueIsEmpty(obj)) ? -1 : obj -> items[(obj -> head + 1) % obj -> cap];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    printf("TAIL: %d\n", obj -> tail);
    return (myCircularQueueIsEmpty(obj)) ? -1 : obj -> items[(obj -> tail != 0) ? (obj -> tail - 1) : (obj -> cap - 1)];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return ((((obj -> head) + 1) % (obj -> cap)) == (obj -> tail % obj -> cap));
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj -> head) == (obj -> tail) % (obj -> cap));
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj -> items);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */
