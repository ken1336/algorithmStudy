#include <iostream>
#include "Mutex.hpp"
#include "SharedResource.hpp"
#include "SharedResource2.hpp"
#include <vector>
int main()
{

    min::SharedResource<int> sh(0);
    min::SharedResource2<int> sh2(0);
    //std::cout<<sh.Get()->Get()<<std::endl;
    //std::cout<<sh.getT()<<std::endl;
    //std::cout<<sh.get()<<std::endl;

    sh.GetWithLock().Get() = 3;
    auto tt = sh.GetWithLock();
    //tt = 5;
    // std::cout << sh.GetWithLock().Get() << std::endl;
    std::cout << "end" << std::endl;
    // min::SharedResource<std::vector<int>> re;
    // re.GetWithLock().Get().push_back(10);
    // re.GetWithLock().Get().push_back(20);
    // std::cout << "iter start" << std::endl;
    // for (auto &iter : re.GetWithLock().Get())
    // {
    //     std::cout << iter << std::endl;
    //     iter++;
    // }

    // for (auto &iter : re.GetWithLock().Get())
    // {
    //     std::cout << iter << std::endl;
    // }

    //return 0;
}