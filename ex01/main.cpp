#include <iostream>
#include <cmath>
#include "Span.hpp"

int main()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << YELLOW << "- Subject test" << NC << std::endl << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "- Shortest: " << CYAN << sp.shortestSpan() << NC << std::endl;
        std::cout << "- Longest:  " << CYAN << sp.longestSpan() << NC << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << YELLOW << "- Trying to add an element when the span is full" << NC << std::endl << std::endl;
    try
    {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    }
    catch (std::exception &e)
    {
        std::cout << NC << "EXCEPTION : ( " << e.what() << " )" << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << YELLOW << "- Trying to use a method when the span is empty" << NC << std::endl << std::endl;
    try
    {
        Span sp = Span(2);
        std::cout << CYAN << sp.shortestSpan() << NC << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << NC << "EXCEPTION : ( " << e.what() << " )" << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << YELLOW << "- Trying to use a method when there's only one element in the span" << NC << std::endl << std::endl;
    try
    {
        Span sp = Span(2);
        sp.addNumber(1);
        std::cout << CYAN << sp.shortestSpan() << NC << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << NC << "EXCEPTION : ( " << e.what() << " )" << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << YELLOW << "- Adding 10000 random elements in the span" << NC << std::endl << std::endl;
    {
        std::list<int> tmp;
        srand(time(NULL));
        for (int i = 0; i < 10000; i++)
            tmp.push_back(rand());
            //tmp.push_back(i);
        Span sp = Span(10000);
        sp.addRange(tmp.begin(), tmp.end());
        std::cout << sp.infoSpan() << std::endl;
        std::cout << "- Shortest: " << CYAN << sp.shortestSpan() << NC << std::endl;
        std::cout << "- Longest:  " << CYAN << sp.longestSpan() << NC << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << YELLOW << "- Trying to add 20000 elements in the span(10000)" << NC << std::endl << std::endl;
    try
    {
        std::list<int> tmp;
        srand(time(NULL));
        for (int i = 0; i < 20000; i++)
            tmp.push_back(rand());
        Span sp = Span(10000);
        sp.addRange(tmp.begin(), tmp.end());
    }
    catch (std::exception &e)
    {
        std::cout << NC << "EXCEPTION : ( " << e.what() << " )" << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    return (0);
}