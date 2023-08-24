#include <iostream>
#include "dynamicarray.h"
#include "timer.h"

int main() {
    const int MILLION = 1000000;

    {
        Timer timer;
        DynamicArray<int> array;

        for (int i = 0; i < MILLION; i++)
        {
            array.Add(i);
        }
        std::cout << array.Length() << std::endl;
        std::cout << array.Get(array.Length() - 1) << std::endl;
    }

    return 0;
}
