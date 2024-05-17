#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{}

Span::Span(Span const &other)
{
    *this = other;
}

Span &Span::operator=(Span const &other)
{
    this->_list = other._list;
    this->_n = other._n;
    return (*this);
}

Span::~Span()
{}

void    Span::addNumber(int num)
{
    if (_list.size() == _n)
        throw std::runtime_error(RED "The span is full" NC);
    _list.push_back(num);
}

unsigned int    Span::shortestSpan()
{
    if (_list.size() == 0)
        throw std::runtime_error(RED "The span is empty" NC);
    else if (_list.size() == 1)
        throw std::runtime_error(RED "There is only one element in the span" NC);
    unsigned int dist = UINT_MAX;
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it)
    {
        for (std::list<int>::const_iterator it2 = _list.begin(); it2 != _list.end(); ++it2)
        {
            if (it == it2) 
                continue    ;
            if (std::abs(*it2 - *it) < dist)
                dist = std::abs(*it2 - *it);
        }
    }
    return (dist);
}

unsigned int    Span::longestSpan()
{
    if (_list.size() == 0)
        throw std::runtime_error(RED "The span is empty" NC);
    else if (_list.size() == 1)
        throw std::runtime_error(RED "There is only one element in the span" NC);
    return (*std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end()));
}

void    Span::addRange(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
    int distance = std::distance(begin, end);
    std::stringstream ss;
    ss << RED << "The span has no space to accommodate " << distance << " elements" << NC;
    if (_list.size() + distance > _n)
        throw std::runtime_error(ss.str());
    _list.insert(_list.end(), begin, end);
}

std::string Span::infoSpan()
{
    std::stringstream ss;
    ss << NC << "- Min value: " << GREEN << *std::min_element(_list.begin(), _list.end()) << std::endl;
    ss << NC << "- Max value: " << GREEN << *std::max_element(_list.begin(), _list.end()) << NC << std::endl;
    return (ss.str());
}