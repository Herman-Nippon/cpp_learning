// Numbers divisible by only 3 should print “fizz”.
// Numbers divisible by only 5 should print “buzz”.
// Numbers divisible by only 7 should print “pop”.
// Numbers divisible by only 11 should print “bang”.
// Numbers divisible by only 13 should print “jazz”.
// Numbers divisible by only 17 should print “pow”.
// Numbers divisible by only 19 should print “boom”.
// Numbers divisible by more than one of the above should print each of the words associated with its divisors.
// Numbers not divisible by any of the above should just print the number.


#include <iostream>
#include <iterator> // for std::size

void printAllDivisors(int num)
{
    const int divisors[] {3, 5, 7, 11, 13, 17, 19};
    const std::string_view words[] {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    bool printed {false};

    for (int i {0}; i < static_cast<int>(std::size(divisors)); ++i)
    {
        if (num % divisors[i] == 0)
        {
            std::cout << words[i];
            printed = true;
        }
    }

    if (!printed)
        std::cout << num;
    std::cout << '\n';
}

int main()
{
    const int startNum {1};
    const int endNum {150};

    for (int i {startNum}; i <= endNum; ++i)
    {
        printAllDivisors(i);
    }

    return 0;
}
