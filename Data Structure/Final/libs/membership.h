#ifndef __CX_MEMBERSHIP__
    #define __CX_MEMBERSHIP__

    struct membership_t {
        char* name;
        int id;
        int points;
    };
    
    typedef struct membership_t* membership;
    
#endif