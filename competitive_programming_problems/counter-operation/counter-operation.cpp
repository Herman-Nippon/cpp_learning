#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n{0}, i{0};
    std::cin >> n;

    int *array = new int[n];
    int maxGrade{1}, minGrade{5};

    for (i = 0; i < n; ++i)
    {
        int temp;
        std::cin >> temp;
        if (temp > maxGrade)
            maxGrade = temp;
        if (temp < minGrade)
            minGrade = temp;
        array[i] = temp;
    }

    for (i = 0; i < n; ++i)
    {
        if (array[i] == maxGrade)
            array[i] = minGrade;
    }

    for (i = 0; i < n; ++i)
    {
        std::cout << array[i] << ' ';
    }

    delete[] array;
    return 0;
}
