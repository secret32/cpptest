#include "thread.h"

sec::Thread::Thread(thread_run func)
{
    this->func = func;
}

sec::Thread::~Thread()
{
    if (this->alive)
    {
#ifdef WIN32
        if (handle_t)
            CloseHandle(handle_t);
        ExitThread(0);
        //TerminateThread(handle_t, 0);
    }
#endif // WIN32
    this->func = 0;
}

void sec::Thread::start()
{
    this->alive = true;
    this->interrupt = false;
#ifdef WIN32
    handle_t = CreateThread(NULL, 0, winThread, this, 0, &id);
    if (!handle_t)
    {
        return;
    }
    //CloseHandle(handle_t);
#endif // WIN32
}

sec::thread_t sec::Thread::getId()
{
    return this->id;
}

void sec::Thread::stop()
{
    this->alive = true;
    this->interrupt = true;
}

#ifdef WIN32
DWORD WINAPI winThread(LPVOID lpParamter)
{
    sec::Thread *t = (sec::Thread*)lpParamter;
    while (t->isAlive() && !t->isInterrupt())
    {
        t->run();
    }
    return NULL;
}
#endif // WIN32

void sec::Thread::run()
{
    if (this->func)
        func();
}
