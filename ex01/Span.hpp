#pragma once

#include <list>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>
#include <climits>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define VIOLET "\e[35m"
#define CYAN "\e[36m"
#define NC "\e[0m"

class Span
{
    public:
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();
        void            addNumber(int num);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
        void            addRange(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
        std::string     infoSpan();
    private:
        Span();
        std::list<int>  _list;
        unsigned int    _n;
};