#include <iostream>
#include <algorithm> //for std::sort
#include <iterator> //for std::size

int main()
{
    int array[]{9, 8, 7, 6, 5, 5, 2, 4, 14, 10};

    std::sort(std::begin(array), std::end(array));
    for (int i {0}; i < static_cast<int>(std::size(array)); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    return 0; 
}
