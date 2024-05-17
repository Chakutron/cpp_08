#include <vector>
#include "easyfind.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int>    vect(numbers, numbers + sizeof(numbers) / sizeof(int));
        return (easyfind(vect, std::atoi(argv[1])));
    }
    else
        std::cout << "- Usage: " << GREEN << "./ex00" << CYAN << " <value to find>" << NC << std::endl;
    return (1);
}