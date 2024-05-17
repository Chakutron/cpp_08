template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other): std::stack<T>(other)
{}

template <typename T>
MutantStack<T>::~MutantStack() 
{
    this->c.clear();
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) 
{
    if (other != *this) 
        this->c = other.c;
    return (*this);
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}