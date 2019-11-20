#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_longest(const char *s, int *left, int *right, int n)
{
	int l = *left;
	int r = *right;
	int len = r-l+1;
	while(--l>=0&&++r<n)
	{
		if(s[l]!=s[r])
		{
			break;
		}
		len+=2;
		*left = l;
		*right = r;
	}
	return len;
}

int longest_palindromic_substr(const char *s, int n, int *pLeft, int *pRight)
{
	int maxlen = 0, left = 0, right = 0, sublen=0;
	int i = 0;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			left = i;
			right = i+1;
			sublen=find_longest(s,&left,&right,n);
		}
		else
		{
			left = i;
			right = i;
			sublen=find_longest(s,&left,&right,n);
		}

		if(sublen>maxlen)
		{
			maxlen=sublen;
			*pLeft = left;
			*pRight = right;
		}
	}
	return maxlen;
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("%s usage:<string>\r\n", argv[0]);
		return -1;
	}

	char *s = argv[1];
	int l, r;
	int len = longest_palindromic_substr(s, strlen(s), &l, &r);
	printf("longest len:[%d]\r\n", len);
	int i = 0;
	for(i=l;i<=r;i++)
	{
		printf("%c", s[i]);
	}

	printf("\r\n");
	return 0;
}
