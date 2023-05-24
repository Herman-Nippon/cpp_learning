#include <iostream>
#include <iterator>

void fillArray(int* array)
{
    for (int i {0}; i < 10; ++i)
    {
        *(array + i) = i * 5;
        //array[i] = i * 5;
    }
}

void printArray(int array[10])
{
    for (int i {0}; i < 10; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int array[10]{};
    printArray(array);
    fillArray(array);
    printArray(array);

    return 0;
}
