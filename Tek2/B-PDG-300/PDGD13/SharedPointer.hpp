/*
** EPITECH PROJECT, 2024
** SharedPointer.hpp
** File description:
** SharedPointer.hpp
*/

#pragma once

#include <cstddef>

template<typename T>
class SharedPointer {
public:
    SharedPointer(T *ptr = nullptr)
        : _ptr(ptr)
    {
        if (ptr == nullptr) {
            this->_count = nullptr;
        } else {
            this->_count = new std::size_t(1);
        }
    }

    SharedPointer(const SharedPointer &other)
        : _count(other._count), _ptr(other._ptr)
    {
        if (this->_count != nullptr)
            (*this->_count)++;
    }

    SharedPointer(SharedPointer &&other)
        : _count(other._count), _ptr(other._ptr)
    {
        other._count = nullptr;
        other._ptr = nullptr;
    }

    SharedPointer &operator=(const SharedPointer &other)
    {
        if (this->_count == other._count)
            return *this;

        if (this->_ptr != nullptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_count;
                delete this->_ptr;
            }
        }

        this->_count = other._count;
        this->_ptr = other._ptr;

        if (this->_count != nullptr)
            (*this->_count)++;

        return *this;
    }

    SharedPointer &operator=(T *ptr)
    {
        if (this->_ptr == ptr)
            return *this;

        if (this->_ptr != nullptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_count;
                delete this->_ptr;
            }
        }

        this->_ptr = ptr;

        if (ptr == nullptr) {
            this->_count = nullptr;
        } else {
            this->_count = new std::size_t(1);
        }

        return *this;
    }

    SharedPointer &operator=(SharedPointer &&other)
    {
        if (other._count == this->_count)
            return *this;

        if (this->_ptr != nullptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_count;
                delete this->_ptr;
            }
        }

        this->_count = other._count;
        this->_ptr = other._ptr;

        other._count = nullptr;
        other._ptr = nullptr;
    }

    ~SharedPointer()
    {
        if (this->_count != nullptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }
    }

    T *get() const
    {
        return this->_ptr;
    }

    T &operator*() const
    {
        return *this->_ptr;
    }

    T *operator->() const
    {
        return this->_ptr;
    }

    std::size_t use_count() const
    {
        if (this->_count == nullptr)
            return 0;
        return *this->_count;
    }

    void reset(T *ptr = nullptr)
    {
        if (this->_ptr == ptr)
            return;

        if (this->_ptr != nullptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_count;
                delete this->_ptr;
            }
        }

        this->_ptr = ptr;

        if (ptr == nullptr) {
            this->_count = nullptr;
        } else {
            this->_count = new std::size_t(1);
        }
    }

    void swap(SharedPointer &other)
    {
        T *tmp_ptr = this->_ptr;
        std::size_t *tmp_count = this->_count;

        this->_ptr = other._ptr;
        this->_count = other._count;

        other._ptr = tmp_ptr;
        other._count = tmp_count;
    }

private:
    std::size_t *_count;
    T *_ptr;
};
