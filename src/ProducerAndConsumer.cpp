#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <condition_variable>
class Store
{
public:
    std::vector<std::string> thing;
    std::mutex key;
};

Store *s = new Store;

void p(std::string name, Store *s)
{
    std::unique_lock<std::mutex> lock(s->key);
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        while (s->thing.size() >= 20)
        {
            /* code */
        }
        s->thing.push_back(name);
    }
}