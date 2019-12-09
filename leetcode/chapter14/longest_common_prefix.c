#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest_common_prefix(char *pp[], char **ppret)
{
    if(NULL == pp || pp[0] == NULL)
    {
        return -1; 
    }

    char *pret = malloc(strlen(pp[0])+1);
    *pret = 0;

    int i = 0, j = 1;
    char *tmp = NULL;
    for(i = 0; i < strlen(pp[0]); i++)
    {
        j = 1;
        for(tmp = pp[j]; tmp != NULL;  j++, tmp=pp[j])
        {
            if(tmp[i] == NULL || tmp[i] != pp[0][i]) 
            {
                pret[i] = 0;
                *ppret = pret;
                return 0; 
            }
        }

        pret[i] = pp[0][i];
    }

    pret[i] = 0;
    *ppret = pret;
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <str> <str> \r\n", argv[0]); 
        return -1;
    }

    int n = argc;
    char **pp = malloc(sizeof(char *)*n);
    int i = 0;
    for(i = 0; i < n; i++)
    {
        pp[i] = argv[i+1]; 
    }
    pp[i] = NULL;

    char *ret = NULL;
    longest_common_prefix(pp, &ret);
    printf("longest common prefix is [%s]\r\n", ret);
    return 0;
}
