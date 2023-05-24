#include <iostream>
#include <ctime>
#include <cstdlib>

constexpr int rowNum{8};
constexpr int colNum{8};

void fillArray(int array[rowNum][colNum])
{
    srand(time(0));

    for (int i{0}; i < rowNum; ++i)
    {
        for (int j{0}; j < colNum; ++j)
        {
            array[i][j] = 1 + (rand() % 20);
        }
    }
}

void swapInt(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void sortSelectionRows(int array[rowNum][colNum])
{
    for (int row{0}; row < rowNum; ++row)
    {
        for (int iteration{0}; iteration < colNum - 1; ++iteration)
        {
            int minValueInd{iteration};
            for (int col{iteration + 1}; col < colNum; ++col)
            {
                if (array[row][minValueInd] > array[row][col])
                    minValueInd = col;
            }
            swapInt(&array[row][iteration], &array[row][minValueInd]);
        }
    }
}

void sortSelectionCols(int array[rowNum][colNum])
{
    for (int col{0}; col < colNum; ++col)
    {
        for (int iteration{0}; iteration < colNum - 1; ++iteration)
        {
            int minValueInd{iteration};
            for (int row{iteration + 1}; row < rowNum; ++row)
            {
                if (array[minValueInd][col] > array[row][col])
                    minValueInd = row;
            }
            swapInt(&array[iteration][col], &array[minValueInd][col]);
        }
    }
}

void copy2dArray(int copied_array[rowNum][colNum], int array[rowNum][colNum])
{
    for (int i{0}; i < rowNum; ++i)
    {
        for (int j{0}; j < colNum; ++j)
        {
            array[i][j] = copied_array[i][j];
        }
    }
}

void sortSelection2dArray(int array[rowNum][colNum])
{
    sortSelectionRows(array);
    sortSelectionCols(array);
}

void printArray(int array[rowNum][colNum])
{
    for (int i{0}; i < rowNum; ++i)
    {
        for (int j{0}; j < colNum; ++j)
        {
            std::cout << array[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

int main()
{
    int array[rowNum][colNum]{0};
    int array1[rowNum][colNum]{0};
    int array2[rowNum][colNum]{0};
    fillArray(array);
    copy2dArray(array, array1);
    copy2dArray(array, array2);

    std::cout << "The original array:\n";
    printArray(array);
    std::cout << '\n';

    std::cout << "After sorting in rows:\n";
    sortSelectionRows(array);
    printArray(array);
    std::cout << '\n';

    std::cout << "After sorting in columns:\n";
    sortSelectionCols(array1);
    printArray(array1);
    std::cout << '\n';

    std::cout << "Full sort of the array:\n";
    sortSelection2dArray(array2);
    printArray(array2);
    std::cout << '\n';

    return 0;
}
