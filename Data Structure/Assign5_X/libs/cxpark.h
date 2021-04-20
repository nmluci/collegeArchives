#ifndef __CX_PARK__
    #define __CX_PARK__
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    struct llist_t {
        int data;
        struct llist_t* next;
    };
    
    struct queue_t {
        int front;
        struct llist_t* data;
        int rear;    
    };

    struct stack_t {
        int top;
        struct llist_t* data;
    };
    
    typedef struct llist_t* llist;
    typedef struct queue_t* queue;
    typedef struct stack_t* stack;
    
    // Init
    extern queue newQueue(queue obj);
    extern llist newList(llist obj, int item);
    extern stack newCache(stack obj);
    
    // Operation
    extern void enqueueCar(queue obj, int item);
    extern void dequeueCar(queue obj, int item);
    extern void pushCache(stack obj, int item);
    extern llist popCache(stack obj);

    // Condition
    extern int isEmptyQueue(queue obj);
    extern int isEmptyStack(stack obj);
    extern void printPark(queue obj);

    // Utilities
    extern queue randPark(queue obj, unsigned size);

    // Destructor
    extern void deleteCache(stack obj);

#endif