
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

// copy constructor
Vector::Vector(const Vector &other) {
    _data = new int[other._size];
    _size = other._size;
    _capacity = other._size;
    for (int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

// assignment operator
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

// operator [] that returns a reference to the element at position index in the vector container.
int &Vector::operator[](int index) {
    if(index < 0 || index >= _size)
        throw std::out_of_range("index out of range");
    return _data[index];
}

// operator [] const that return int
int Vector::operator[](int index) const {
    if(index < 0 || index >= _size)
        throw std::out_of_range("index out of range");
    return _data[index];
}

// return true if the vector is empty, and false otherwise.
bool Vector::empty() {
    return _size == 0;
}

// return the number of elements in the vector.
int Vector::size() const {
    return _size;
}

// return a pointer to the first element in the vector.
int *Vector::data() const {
    return _data;
}

// swap the contents of the container by the contents of other, which is another vector object of the same type.
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

// reserve newCapacity
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

// return the number of elements that the vector can hold before needing to allocate more memory.
size_t Vector::capacity() const {
    return _capacity;
}

// clear the contents of the vector, which are destroyed, leaving the container with a size of 0.
void Vector::clear() {
    delete[] _data;
    _data = new int[2];
    _size = 2;
    _capacity = 0;
}

// add value to the end of the vector.
void Vector::push_back(int value) {
    if (_size == _capacity)
        reserve(_capacity * (_size < 128) ? 2 : 1.5);
    _data[_size] = value;
    _size++;
}

// remove the last element of the vector.
void Vector::pop_back() {
    if (_size == 0)
        throw std::out_of_range("index out of range");
    _size--;
}

// check if the vector contains same elements as other
bool Vector::operator==(const Vector &other) const {
    if (_size != other._size)
        return false;
    for (int i = 0; i < _size; i++) {
        if (_data[i] != other._data[i])
            return false;
    }
    return true;
}

// check if the pointer of the vector is not equal to the pointer of other
bool Vector::operator!=(const Vector &other) const {
    return !(*this == other);
}

// check if the vector is bigger than other
bool Vector::operator>=(const Vector &other) const {
    if (_size < other._size)
        return false;
    for (int i = 0; i < other._size; i++) {
        if (_data[i] < other._data[i])
            return false;
    }
    return true;
}

// check if the vector is smaller than other
bool Vector::operator<=(const Vector &other) const {
    if (_size > other._size)
        return false;
    for (int i = 0; i < _size; i++) {
        if (_data[i] > other._data[i])
            return false;
    }
    return true;
}

void Vector::insert(int index, int value) {

}

void Vector::erase(int index) {

}