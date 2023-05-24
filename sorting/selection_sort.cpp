#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 30, 50, 20, 10, 40 };
    constexpr int length {static_cast<int>(std::size(array))};

    for (int i {0}; i < length - 1; ++i)
    {
        int max_index {i};
        for (int j {i + 1}; j < length; ++j)
        {
            if (array[max_index] < array[j])
                max_index = j;
        }
        std::swap(array[i], array[max_index]);
    }
    
    for (int i {0}; i < length; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}
