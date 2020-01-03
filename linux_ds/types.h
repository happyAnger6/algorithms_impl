#ifndef _TYPES_H
#define _TYPES_H

#define container_of(ptr, type, member) ({  \
    const typeof( ((type *)0)->member) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type, member));})


#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#endif
