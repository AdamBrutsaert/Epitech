/*
** EPITECH PROJECT, 2024
** List.cpp
** File description:
** List.cpp
*/

#include "List.hpp"

const char *List::InvalidOperationException::what() const noexcept
{
    return "Invalid operation on a list";
}

List::~List()
{
    for (IObject *elem : this->_list)
        delete elem;
}

bool List::empty() const
{
    return this->_list.empty();
}

std::size_t List::size() const
{
    return this->_list.size();
}

IObject *&List::front()
{
    if (this->_list.empty())
        throw InvalidOperationException();
    return this->_list.front();
}

IObject *List::front() const
{
    if (this->_list.empty())
        throw InvalidOperationException();
    return this->_list.front();
}

IObject *&List::back()
{
    if (this->_list.empty())
        throw InvalidOperationException();
    return this->_list.back();
}

IObject *List::back() const
{
    if (this->_list.empty())
        throw InvalidOperationException();
    return this->_list.back();
}

void List::pushBack(IObject *obj)
{
    this->_list.push_back(obj);
}

void List::pushFront(IObject *obj)
{
    this->_list.push_front(obj);
}

void List::popFront()
{
    if (!this->_list.empty()) {
        delete this->_list.front();
        this->_list.pop_front();
    } else {
        throw InvalidOperationException();
    }
}

void List::popBack()
{
    if (!this->_list.empty()) {
        delete this->_list.back();
        this->_list.pop_back();
    } else {
        throw InvalidOperationException();
    }
}

void List::clear()
{
    for (IObject *elem : this->_list)
        delete elem;

    this->_list.clear();
}

void List::forEach(void (*function)(IObject *))
{
    for (IObject *elem : this->_list)
        function(elem);
}

List::Iterator List::begin() const
{
    return List::Iterator(this->_list, this->_list.begin());
}

List::Iterator List::end() const
{
    return List::Iterator(this->_list, this->_list.end());
}

List::Iterator List::erase(List::Iterator it)
{
    if (&it.getList() != &this->_list)
        throw List::InvalidIteratorException();
    if (it == this->end())
        throw List::InvalidIteratorException();
    delete *it;
    return List::Iterator(this->_list, this->_list.erase(it.getIterator()));
}

List::Iterator List::insert(List::Iterator it, IObject *obj)
{
    if (&it.getList() != &this->_list)
        throw List::InvalidIteratorException();
    return List::Iterator(this->_list, this->_list.insert(it.getIterator(), obj));
}

List::Iterator::Iterator(const std::deque<IObject *> &list, std::deque<IObject *>::const_iterator it)
    : _list(list), _it(it)
{
}

IObject *List::Iterator::operator*() const
{
    if (this->_it == this->_list.end())
        throw List::Iterator::OutOfRangeException();
    return *this->_it;
}

List::Iterator& List::Iterator::operator++()
{
    if (this->_it == this->_list.end())
        throw List::Iterator::OutOfRangeException();
    this->_it++;
    return *this;
}

bool List::Iterator::operator==(const Iterator& it) const
{
    return this->_it == it._it;
}

bool List::Iterator::operator!=(const Iterator& it) const
{
    return this->_it != it._it;
}

std::deque<IObject *>::const_iterator List::Iterator::getIterator() const
{
    return this->_it;
}

const std::deque<IObject *> &List::Iterator::getList() const
{
    return this->_list;
}
