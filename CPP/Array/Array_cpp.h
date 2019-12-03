#ifndef __ARRAY_CPP__H
#define __ARRAY_CPP__H

#include <iostream>

template<typename T>
class Array {
public:
    Array(size_t capacity);
    ~Array();

    size_t find(T value);
    T get(size_t index);

    bool insert(size_t index, T value);
    bool remove(size_t index);

private:
    friend std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
        for(size_t i = 0; i < array.len; ++i) {
            out << array.data[i];
            out << " ";
        }

        return out;
    }

private:
    T* data;
    size_t len;
    size_t capacity;
};

#endif

template<typename T>
inline Array<T>::Array(size_t capacity) {
    this->data = new T(capacity);
    /*if(nullptr == this->data) {
        throw std::bad_alloc("内存不足");
    }*/

    this->capacity = capacity;
    this->len = 0;
}

template<typename T>
inline Array<T>::~Array() {
    /* if(nullptr != this->data) {
         delete[] this->data;
         this->data = nullptr;
     }*/
}

template<typename T>
inline size_t Array<T>::find(T value) {
    size_t pos = -1;
    for(size_t i = 0; i < this->len; ++i) {
        if(value == this->data[i]) {
            pos = i;
            break;
        }
    }

    return pos;
}

template<typename T>
inline T Array<T>::get(size_t index) {
    if(index < 0 || index >= this->len) {
        throw std::out_of_range("超出数组的长度范围");
    }

    return this->data[index];
}

template<typename T>
inline bool Array<T>::insert(size_t index, T value) {
    if(index < 0 || index > this->len) {
        throw std::out_of_range("超出数组的长度范围");
    }

    if(this->len == this->capacity) {
        throw std::range_error("超出数组的容量限制");
    }

    for(size_t i = this->len + 1; i > index; --i) {
        this->data[i] = this->data[i - 1];
    }

    this->data[index] = value;
    ++ this->len;
    return true;
}

template<typename T>
inline bool Array<T>::remove(size_t index) {
    if(index < 0 || index >= this->len) {
        throw std::out_of_range("超出数组的长度范围");
    }

    for(size_t i = index + 1; i < this->len; ++i) {
        this->data[i - 1] = this->data[i];
    }
    -- this->len;
    return true;
}
