#include "unp.h"

int main(int argc, char *argv[])
{
    int sockfd;
    if(argc<2)
    {
        printf("usage:%s <IPaddr>\r\n", argv[0]);
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("socket error\r\n");
        return -1; 
    }

    struct sockaddr_in srvaddr;
    bzero(&srvaddr, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(13);
    if(inet_pton(AF_INET, argv[1], &srvaddr.sin_addr)<0)
    {
        close(sockfd);
        sockfd = -1;
        return -1; 
    }

    if(connect(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr))<0)
    {
        printf("connect error\r\n");
        return -1; 
    }

    char buf[MAXLINE+1];
    buf[0] = 0;
    int n;
    while((n = read(sockfd, buf, MAXLINE))>0)
    {
        buf[n]=0;
        if(fputs(buf, stdout) == EOF)
        {
            printf("fputs error\r\n");
            return -1; 
        } 
    }

    if(n<0)
    {
        printf("system error\r\n"); 
    }

    return 0;
}
