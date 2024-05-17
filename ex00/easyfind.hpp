#pragma once

#include <iostream>
#include <algorithm>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define VIOLET "\e[35m"
#define CYAN "\e[36m"
#define NC "\e[0m"

template <typename T>
int    easyfind(T &container, int value)
{
    if (std::find(container.begin(), container.end(), value) == container.end())
    {
        std::cout << "- Value " << value << RED << " NOT FOUND " << NC << "in the container." << std::endl;
        return (1);
    }
    std::cout << "- Value " << value << GREEN << " FOUND " << NC << "in the container." << std::endl;
    return (0);
}