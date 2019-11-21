#include <stdio.h>
#include <stdlib.h>


int mystrlen(const char *s)
{
    int len = 0;
    if(NULL == s)
        return 0;

    while(*s!=0)
        len++;

    return len;
}

int mystrcpy(char *dst, char *src)
{
    if(NULL == dst || NULL == src)
        return 0;

    while(0!=*src)
    {
        *dst++=*src++;
    }
    *dst = 0;
}

int mystrlcpy(char *dst, char *src, int n)
{
    if(NULL == dst || NULL == src)
        return 0;

    while(0!=*src&&--n)
    {
        *dst++=*src++;
    }
    *dst = 0;
}

int mystrcmp(char *s1, char *s2)
{
    if(s1==s2)
        return 0;

    if(NULL == s1|| NULL == s2)
    {
        if(NULL != s1)
            return *s1;
        
        return *s2; 
    }

    while(*s1==*s2)
    {
        if(*s1== 0)
            return 0;
        s1++;
        s2++;
    }

    return *s1- *s2;
}
