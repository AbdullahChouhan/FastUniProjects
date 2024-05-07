#include <fstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    std::string line;
    while (std::getline(input, line))
    {
        size_t pos = line.find("..");
        while (pos != std::string::npos)
        {
            line.erase(pos + 1, 2);
            if (line[pos + 2] >= 'a' && line[pos + 2] <= 'z') {
                line[pos + 2] = line[pos + 2] - 32;
            }
            pos = line.find("..", pos + 1);
        }
        output << line << '\n';
    }
    return 0;
}