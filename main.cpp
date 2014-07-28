#include <iostream>
#include "thread.h"

void test()
{
    std::cout<<"Fun display!"<<std::endl;
    Sleep(1000);
}

int main()
{
    sec::Thread t(test);
    t.start();
    std::cout << "t.id=" << t.getId() << std::endl;
    for (int i = 0; i < 30; i++)
    {
        if(i == 5)
            t.stop();
        std::cout<<"Main display!"<<std::endl;
        Sleep(500);
    }
    std::cout << "Main exit" << std::endl;
    return 0;
}
