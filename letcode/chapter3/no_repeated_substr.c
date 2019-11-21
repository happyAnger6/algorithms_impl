#include <stdio.h>
#include <stdlib.h>

int no_repeated_substr(const char* src, int n)
{
    int start = 0, end = 0, sublen = 0;
    char c;
    int seen[256] = {0};

    while(i<=n)
    {
        c = src[i];
        if(seen[c]>=start && i!=start)
        {
            sublen=end-start;
            if(sublen>maxlen)
            {
                maxstart = start;
                maxend = end;
                maxlen = sublen; 
            } 
            i = seen[c]+1;
            start = i;
            end = i;
        }     
        else
        {
            end=i; 
        }

        seen[c]=i;
        i++;
    }

}
