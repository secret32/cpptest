#include "shelton_net.h"
//#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

char* client(const char* url)
{
    int socket_in = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_in < 0)
        return "can not create socket";
    int r = -1;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(url);

    int i = connect(socket_in, &addr, sizeof(addr));
    if (i < 0)
        return "can not connect to the address";
#ifdef DEBUG
    printf("connect success\n");
#endif
    char sendMsg[] = "GET / HTTP/1.1\r\nAccept:text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language:zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\nConnection:keep-alive\r\nCookie:BAIDUID=2DECE784065B33E6AFF5951157A6AB04:FG=1; H_PS_PSSID=6347_5229_1458_7649_7570_6996_7445_7542_6504_6018_7606_7134_7585_7414_7572_7474\r\nHost:www.baidu.com\r\nUser-Agent:Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:30.0) Gecko/20100101 Firefox/30.0\r\n\r\n";
    if((r = send(socket_in, sendMsg, strlen(sendMsg), 0)) > 0)
    {
#ifdef DEBUG
        printf("send success, sent char: %d\n", r);
#endif
    }
    char buf[BUF_SIZE] = "";
    while ((r = recv(socket_in, buf, BUF_SIZE, 0)) >= 0)
    {
       if (r < BUF_SIZE)
         buf[r] = '\0';
       printf("%s", buf);
    }
    close(socket_in);
    return "ok";
}

void service()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
       printf("can not create socket\n");
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1556);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(sock, &addr, sizeof(addr)) < 0)
       printf("can not bind socket\n");
#ifdef DEBUG
    printf("socket is working....\n");
#endif
    if(listen(sock, 3) < 0)
       printf("can not listen to socket\n");
    while (1)
    {
        int s = accept(sock, NULL, NULL);
        if (!fork())
        {
            char buf[BUF_SIZE];
            int r;
            while ((r = recv(s, buf, BUF_SIZE, 0)) > 0)
            {
                buf[r] = '\0';
                printf("recv: %s\n", buf);
                char *response = "response";
                send(s, response, strlen(response), 0);
            }
        }
        //close(s);
        continue;
    }
    //close(sock);
}

sechost* getSecHost(const char *url)
{
    return NULL;
}
