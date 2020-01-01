#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumFlags(int flags[256])
{
    int sum = 0;
    int i;
    for(i = 0; i < 256; i++)
        sum += flags[i];

    return sum==0 ? 1 : 0;

}
int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage:%s <str1> <str2>\r\n", argv[0]);
        return -1; 
    }

    int charFlags[256] = {0};
    int i, len1, len2;
    char *str1 = argv[1];
    char *str2 = argv[2];

    len1 = strlen(str1);
    len2 = strlen(str2);
    if(len1 != len2)
    {
        printf("False\r\n"); 
        return 1;
    }

    for(i = 0; i < len1; i++)
    {
        charFlags[(int)str1[i]]++;
    }
    
    for(i = 0; i < len2; i++)
    {
        charFlags[(int)str2[i]]--;
    }

    if(1 == sumFlags(charFlags))
    {
        printf("True\r\n");
        return 0; 
    }
        
    printf("False\r\n");
    return 1; 


}
