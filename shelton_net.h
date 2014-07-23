#ifndef WIN32
#ifndef SHELTON_NET_H
#define SHELTON_NET_H

#ifndef WIN32
#include "shelton.h"
#endif

#define LOCALHOST 127.0.0.1
#define PORT 1555
#define BUF_SIZE 1024

typedef struct{
    char* address;
    int port;
} sechost;

char* client(const char* url);

sechost* getSecHost(const char* url);

void service(void);

#endif // SHELTON_NET_H
#endif // WIN32
