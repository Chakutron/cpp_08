#pragma once

#include <stack>
#include <deque>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define VIOLET "\e[35m"
#define CYAN "\e[36m"
#define NC "\e[0m"

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > 
{
    public:
        MutantStack();
        MutantStack(MutantStack const &other);
        MutantStack &operator=(MutantStack const &other);
        ~MutantStack();
        typedef typename std::deque<T>::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"