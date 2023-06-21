#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void trim_line(std::string& str)
{
    auto start = str.find("[[");
    auto end = str.find("]]");
    if (start != std::string::npos && end != std::string::npos)
        str = str.substr(start + 2, end - start - 2);
    else
        str.clear();
}

std::vector<std::string> get_trimmed_lines(std::string path)
{
    std::vector<std::string> surnames;
    std::fstream file(path);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            trim_line(line);
            surnames.push_back(line);
        }
        file.close();
    }
    else 
    {
        std::cout << "Unable to open\n";
    }
    return surnames;
}

int main()
{
    std::vector<std::string> names{"А", "Б", "В", "Е", "Л", "М", "Т", "И", "К"};
    srand(time(NULL));

    int names_amount;
    std::cout << "Amount of names needed: ";
    std::cin >> names_amount;

    std::vector<std::string> surnames {get_trimmed_lines("./text_files/surnames.txt")};

    for (int i = 0; i < names_amount; i++)
    {
        int rand_surname = rand() % (surnames.size());
        int rand_name1 = rand() % (names.size());
        int rand_name2 = rand() % (names.size());
        std::cout << surnames[rand_surname] + " " + names[rand_name1] + ". " + names[rand_name2] + "." << '\n';
    }
}
