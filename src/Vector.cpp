
//
// Created by Dvir Avraham on 19/03/2023.
//

#include "Vector.h"

// implemnt vector

// constructor with size and value
Vector::Vector(size_t size, int value) {
    _data = new int[size];
    _size = size;
    _capacity = size;
    for (int i = 0; i < size; i++) {
        _data[i] = value;
    }
}

// destructor
Vector::~Vector() {
    delete[] _data;
}

//

Vector::Vector(const Vector &other) {
    _data = new int[other._size];
    _size = other._size;
    _capacity = other._size;
    for (int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

Vector &Vector::operator=(const Vector &other) {
    if (this != &other) {
        delete[] _data;
        _data = new int[other._size];
        _size = other._size;
        _capacity = other._size;
        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

int &Vector::operator[](int index) {
    if(index < 0 || index >= _size)
        throw std::out_of_range("index out of range");
    return _data[index];
}

int Vector::operator[](int index) const {
    if(index < 0 || index >= _size)
        throw std::out_of_range("index out of range");
    return _data[index];
}

bool Vector::empty() {
    return _size == 0;
}

int Vector::size() const {
    return _size;
}

int *Vector::data() const {
    return _data;
}

void Vector::swap(Vector &other) {
    int* tempData = _data;
    int tempSize = _size;
    int tempCapacity = _capacity;
    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;
    other._data = tempData;
    other._size = tempSize;
    other._capacity = tempCapacity;
}

void Vector::reserve(size_t newCapacity) {
    if (newCapacity > _capacity) {
        int* tempData = new int[newCapacity];
        for (int i = 0; i < _size; i++) {
            tempData[i] = _data[i];
        }
        delete[] _data;
        _data = tempData;
        _capacity = newCapacity;
    }
}

size_t Vector::capacity() const {
    return _capacity;
}

void Vector::clear() {
    delete[] _data;
    _data = new int[2];
    _size = 2;
    _capacity = 0;
}

void Vector::push_back(int value) {
    if (_size == _capacity)
        reserve(_capacity * (_size < 128) ? 2 : 1.5);
    _data[_size] = value;
    _size++;
}

void Vector::pop_back() {
    if (_size == 0)
        throw std::out_of_range("index out of range");
    _size--;
}
