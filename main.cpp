#include <iostream>
#include "dynamicarray.h"

int main() {
    DynamicArray<int> array;
    array.Add(1);
    array.Add(2);
    array.Add(3);
    array.Add(50);
    array.Add(100);
    array.Add(34);
    array.Add(2);
    array.Add(3);
    array.Add(50);
    array.Add(100);
    array.Add(1);
    array.Add(2);
    array.Add(3);
    array.Add(50);
    array.Add(100);
    std::cout << array.Length() << std::endl;
    std::cout << array.Get(array.Length() - 1) << std::endl;

    array.Remove(array.Length() - 1);
    std::cout << array.Length() << std::endl;
    std::cout << array.Get(array.Length() - 1) << std::endl;

    std::cout << array.Contains(34) << std::endl;
    return 0;
}
