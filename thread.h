#ifndef THREAD_H
#define THREAD_H

#ifdef WIN32
#include <windows.h>
DWORD WINAPI winThread(LPVOID lpParamter);
#endif // WIN32

namespace sec {
typedef unsigned long int thread_t;
typedef void (*thread_run)();
class Thread
{
public:
    Thread(thread_run);
    ~Thread();
    void start();
    void stop();
    thread_t getId();
    bool isAlive() {return alive;}
    bool isInterrupt() {return interrupt;}
#ifdef WIN32
    HANDLE handle_t;
#endif // WIN32
//protected:
    void run();
private:
    thread_run func;
    bool interrupt;
    bool alive;
    thread_t id;
};
}
#endif // THREAD_H
