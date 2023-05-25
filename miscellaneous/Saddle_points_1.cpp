#include <iostream>
#include <sstream>
#include <string>

constexpr int row{750}, column{750};

void fillArray(int array[row][column], int n, int m)
{
    for (int i{0}; i < n; ++i)
    {
        std::string line{};
        getline(std::cin, line);

        std::stringstream ss(line);
        int number{0}, j{0};

        while (ss >> number)
        {
            array[i][j] = number;
            ++j;
        }
    }
}

int findMinInRow(int array[row][column], int i, int m)
{
    int min_number{array[i][0]};

    for (int j{1}; j < m; ++j)
    {
        if (array[i][j] == 1001)
        {
            break;
        }
        else if (array[i][j] < min_number)
        {
            min_number = array[i][j];
        }
    }
    return min_number;
}

bool isMaxInColumn(int array[row][column], int j, int n, int number)
{
    for (int i{0}; i < n; ++i)
    {
        if (array[i][j] == 1001)
        {
            break;
        }
        else if (array[i][j] > number)
        {
            return false;
        }
    }
    return true;
}

int findCountOfSaddlePoints(int array[row][column], int n, int m)
{
    int count{0};
    for (int i{0}; i < n; ++i)
    {
        int min_number{findMinInRow(array, i, m)};

        for (int j{0}; j < m; j++)
        {
            if ((array[i][j] == min_number) && (isMaxInColumn(array, j, n, min_number)))
            {
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n{0}, m{0};

    std::cin >> n >> m;
    std::cin.ignore();

    int array[row][column]{1001};

    fillArray(array, n, m);

    std::cout << findCountOfSaddlePoints(array, n, m) << '\n';

    return 0;
}
