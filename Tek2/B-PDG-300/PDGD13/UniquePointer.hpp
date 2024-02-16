/*
** EPITECH PROJECT, 2024
** UniquePointer.hpp
** File description:
** UniquePointer.hpp
*/

#pragma once

template<typename T>
class UniquePointer {
public:
    UniquePointer(T* ptr = nullptr)
        : _ptr(ptr)
    {
    }

    UniquePointer(const UniquePointer<T>& other) = delete;

    UniquePointer(UniquePointer<T>&& other)
        : _ptr(other._ptr)
    {
        other._ptr = nullptr;
    }

    UniquePointer<T>& operator=(const UniquePointer<T>& other) = delete;

    UniquePointer<T>& operator=(T *ptr)
    {
        if (this->_ptr == ptr)
            return *this;
        if (this->_ptr != nullptr)
            delete this->_ptr;
        this->_ptr = ptr;
        return *this;
    }

    UniquePointer<T>& operator=(UniquePointer<T>&& other)
    {
        if (this->_ptr == other._ptr)
            return *this;
        if (this->_ptr != nullptr)
            delete this->_ptr;
        this->_ptr = other._ptr;
        other._ptr = nullptr;
        return *this;
    }

    ~UniquePointer()
    {
        if (this->_ptr != nullptr)
            delete this->_ptr;
    }

    T* get() const
    {
        return this->_ptr;
    }

    T* operator->() const
    {
        return this->_ptr;
    }

    T& operator*() const
    {
        return *this->_ptr;
    }

    void reset(T* ptr = nullptr)
    {
        if (this->_ptr == ptr)
            return;
        if (this->_ptr != nullptr)
            delete this->_ptr;
        this->_ptr = ptr;
    }

    void swap(UniquePointer<T>& other)
    {
        T* tmp = this->_ptr;
        this->_ptr = other._ptr;
        other._ptr = tmp;
    }

private:
    T* _ptr;
};
