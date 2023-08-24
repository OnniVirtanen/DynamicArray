#include <iostream>
#include "dynamicarray.h"
#include "timer.h"

#define LOG(x) std::cout << x << std::endl

int main() {
    const int MILLION = 1000000;

    {
        Timer timer;
        DynamicArray<long> array;

        for (long i = 0; i < (MILLION); i++)
        {
            array.Add(i);
        }

        LOG(array.Length());
        LOG(array.Get(array.Length() - 1));
    }

    return 0;
}