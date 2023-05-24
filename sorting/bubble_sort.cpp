#include <iostream>
#include <utility> //for std::swap
#include <iterator> //for std::size

void printArray(int array_length, int array[])
{
    for (int i {0}; i < array_length; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

void customBubbleSort(int array_length, int array[])
{
    for (int already_sorted {0}; already_sorted < array_length - 1; ++already_sorted)
    {
        bool swap_happened {false};
        for (int i {0}; i < array_length - already_sorted - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                swap_happened = true;
            }
        }
        if (!swap_happened)
        {
            std::cout << "The algo stopped at iteration " << already_sorted + 1 << " of " << array_length << '\n';
            break;
        }
    }
}

int main()
{
    int array[]{ 3, 3, 77, 4, 54, 90, 1, 2, 0 };
    constexpr int length {static_cast<int>(std::size(array))};

    printArray(length, array);
    customBubbleSort(length, array);
    printArray(length, array);
    return 0;    
}
