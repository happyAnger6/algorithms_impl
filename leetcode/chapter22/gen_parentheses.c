#include <stdio.h>
#include <stdlib.h>

char **gen_parenth(int left, int right, char *cur, char **res)
{
    if(left == right && left == 0)
    {
        res.append(cur);
        return res;
    }

    if(right < left)
        return;

    gen_parenth(left - 1, right, cur+'(', res);
    gen_parenth(left, right-1, cur+')', res);
    return res;
}
