#include <iostream>
#include <string>

double fetchDouble()
{
    std::cout << "Enter a double value: ";
    double num{};
    std::cin >> num;
    return num;
}

char fetchOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;

}

void calc(double x, double y, char op)
{
    double result{};

    if (op == '+') result = x + y;
    else if (op == '-') result = x - y;
    else if (op == '*') result = x * y;
    else if (op == '/') result = x / y;
    else{
        std::cout << "Incorrect input.\n";
        return;
    }
    std::cout << x << " " << op << " " << y << " = " << result << '\n';
}

int main()
{   
    double num1{ fetchDouble() }, num2{ fetchDouble() };
    char oper{ fetchOperator() };
    calc(num1, num2, oper);
    return 0;
}
