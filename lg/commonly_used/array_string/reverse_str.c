#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <str> \r\n", argv[0]);
        return -1; 
    }

    char *str = argv[1];
    printf("before: [%s]\r\n", str);

    char tmp;
    int head, tail;
    head = 0;
    tail = strlen(str) - 1;
    while(head < tail)
    {
        tmp = str[tail];
        str[tail] = str[head];
        str[head] = tmp;
        head++;
        tail--; 
    }

    printf("after:[%s]\r\n", str);
}
