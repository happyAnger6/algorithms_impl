#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_norepeated_substr(const char *s, int *start, int *end)
{
	int left = 0, right = 0, sublen = 0, maxlen = 0;
	int next[256] = {0};

	if(s==NULL)
		return -1;

	int i;
	char c;
	int n = strlen(s);
	for(i = 0; i < n; i++)
	{
		c = s[i];
		if(next[c] == 0 || next[c] < left)
		{
			if(i-left+1 > maxlen)
			{
				maxlen = i - left + 1;
				*start = left;
				*end = i;
			}
		}
		else
		{
			left = next[c];
		}
		next[c] = i+1;
	}

	return maxlen;
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("usage:%s <string>\r\n");
		return -1;
	}

	int start, end, i;
	if(max_norepeated_substr(argv[1], &start, &end)>=0)
	{
		printf("maxsubstr from %d to %d \r\n", start, end);
		printf("maxsubstr:");
		for(i=start; i<=end; i++)
		{
			printf("%c", argv[1][i]);
		}
		printf("\r\n", argv[i]);
		
	}	
}
