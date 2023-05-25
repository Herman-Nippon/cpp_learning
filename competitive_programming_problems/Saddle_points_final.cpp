#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n{0}, m{0};

    std::cin >> n >> m;
    std::cin.ignore();

    int **array = new int *[n]; // init of two-dimencional array

    for (int i{0}; i < n; ++i)
    {
        array[i] = new int[m];
        for (int j{0}; j < m; ++j) // filling the array with values
            std::cin >> array[i][j];
    }

    int *minRow = new int[n]; // init of one-dim array of minimum values in a row
    for (int i{0}; i < n; ++i)
    {
        minRow[i] = 1001;
        for (int j{0}; j < m; ++j) // filling the array with values
            if (array[i][j] < minRow[i])
                minRow[i] = array[i][j];
    }

    int *maxCol = new int[m]; // init of one-dim array of maximum values in a column
    for (int j{0}; j < m; ++j)
    {
        maxCol[j] = -1001;
        for (int i{0}; i < n; ++i) // filling the array with values
            if (array[i][j] > maxCol[j])
                maxCol[j] = array[i][j];
    }

    int result{0};
    for (int i{0}; i < n; ++i)
        for (int j{0}; j < m; ++j)
            if ((array[i][j] == minRow[i]) && (array[i][j] == maxCol[j])) // checking if current element is min in a row and 
                ++result;                                                 // max in a column

    std::cout << result;

    for (int i{0}; i < n; i++)
        delete[] array[i];
    delete[] array; 
    delete[] minRow;
    delete[] maxCol;

    return 0;
}
