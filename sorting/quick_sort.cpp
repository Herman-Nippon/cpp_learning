#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include <iterator> // for std::size(array)
#include <string>

void fill_array_random(int *array, int array_len, int min_n = 1, int max_n = 100)
{
    // seed the random number generator
    std::srand(std::time(nullptr));

    // fill the array with random numbers
    for (size_t i = 0; i < array_len; i++)
    {
        array[i] = std::rand() % max_n + min_n;
    }
}

void swap_int(int& int1, int& int2)
{
    int temp = int1;
    int1 = int2;
    int2 = temp;
}

int partition(int *array, int start_ind, int end_ind)
{
    int pivot = array[end_ind];
    int i = start_ind - 1;
    for (size_t j = start_ind; j < end_ind; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap_int(array[i], array[j]);
        }
    }
    i++;
    swap_int(array[i], array[end_ind]);

    return i;
}

void quick_sort(int *array, int start_ind, int end_ind)
{
    if (end_ind <= start_ind)
        return;

    int pivot = partition(array, start_ind, end_ind);

    quick_sort(array, start_ind, pivot - 1);
    quick_sort(array, pivot + 1, end_ind);
}

void print_array(int *array, int size)
{
    for (auto it = array; it != array + size; it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

int main(int argc, char *argv[])
{

    int size = 10;
    if (argc == 2)
    {
        std::string strArg = argv[1];
        try
        {
            size = std::stoi(strArg);
        }
        catch (const std::exception &e)
        {
            std::cerr << "You must enter one integer as an argument" << '\n';
        }
    }
    else
    {
        // to change the size, enter it as an argument when running
        std::cout << "To change the default size (10), enter it as an argument when running\n";
    }

    int array[size];

    fill_array_random(array, size);
    print_array(array, size);
    quick_sort(array, 0, size - 1);
    print_array(array, size);

    return 0;
}
