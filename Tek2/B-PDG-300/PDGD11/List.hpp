/*
** EPITECH PROJECT, 2024
** List.hpp
** File description:
** List.hpp
*/

#pragma once

#include "IObject.hpp"

#include <deque>
#include <exception>

class List {
public:
    class InvalidOperationException : public std::exception {
    public:
        virtual const char *what() const noexcept override;
    };

    class InvalidIteratorException : public std::exception {};

    class Iterator {
    public:
        class OutOfRangeException : public std::exception {};

    public:
        Iterator(const std::deque<IObject *> &list, std::deque<IObject *>::const_iterator it);

        IObject *operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;

        std::deque<IObject *>::const_iterator getIterator() const;
        const std::deque<IObject *> &getList() const;

    private:
        const std::deque<IObject *> &_list;
        std::deque<IObject *>::const_iterator _it;
    };

public:
    List() = default;
    List(const List &other) = delete;
    List(List &&other) = delete;
    List &operator=(const List &other) = delete;
    List &operator=(List &&other) = delete;
    ~List();

    bool empty() const;
    std::size_t size() const;

    IObject *&front();
    IObject *front() const;
    IObject *&back();
    IObject *back() const;

    void pushBack(IObject *obj);
    void pushFront(IObject *obj);
    void popFront();
    void popBack();

    void clear();
    void forEach(void (*function)(IObject *));

    List::Iterator begin() const;
    List::Iterator end() const;
    List::Iterator erase(List::Iterator it);
    List::Iterator insert(List::Iterator it, IObject *obj);

private:
    std::deque<IObject *> _list;
};
