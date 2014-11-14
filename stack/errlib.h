#ifndef ERRLIB_H
#define ERRLIB_H

enum error_code {
    noERR,
    rlcERR, // Realloc falls down
    ptrERR // Wrong pointer
};

const char* const errstr[] = {
    "noERR",
    "rlcERR",
    "ptrERR"
};

#ifndef true
    #undef true
    #define true 1
#endif // true

#ifndef false
    #undef false
    #define false 0
#endif // false


#endif // ERRLIB_H
