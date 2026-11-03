#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string line;
    std::string s1;
    std::string s2;
    std::string filename;

    if(ac != 4)
    {
        std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    if(s1.length() == 0)
    {
        std::cout << "s1 should contain something";
        return 1;
    }
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::
    }
}